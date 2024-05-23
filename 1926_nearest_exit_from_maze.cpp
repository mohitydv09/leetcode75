#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <set>
#include <tuple>

using namespace std;

class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int numRows = maze.size();
        int numCols = maze[0].size();

        vector<vector<bool>> visited(numRows, vector<bool>(numCols, false));
        queue<pair<int,int>> frontier;

        int directions[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};

        visited[entrance[0]][entrance[1]] = true;
        for(auto dir : directions){
            int newRow = entrance[0] + dir[0];
            int newCol = entrance[1] + dir[1];
            if(newRow >= 0 && newCol >=0 && newRow < numRows && newCol < numCols && !visited[newRow][newCol] && maze[newRow][newCol] == '.'){
                frontier.push({newRow, newCol});
                visited[newRow][newCol] = true;
            }
        }

        int level = 0;
        while(!frontier.empty()){
            int frontierSize = frontier.size();
            level++;
            for (int i = 0; i < frontierSize; i++){
                auto [currRow, currCol] = frontier.front();
                frontier.pop();
                if(currRow == 0 || currRow == numRows-1 || currCol == 0 || currCol == numCols-1){
                    return level;
                }else{
                    for (auto dir : directions){
                        int newRow = currRow + dir[0];
                        int newCol = currCol + dir[1];
                        if(newRow >= 0 && newCol >=0 && newRow < numRows && newCol < numCols && !visited[newRow][newCol] && maze[newRow][newCol] == '.'){
                            frontier.push({newRow, newCol});
                            visited[newRow][newCol] = true;
                        }
                    }
                }
            }
        }
        return -1;
    }
};

int main(){
    Solution solution_instance;
    vector<vector<char>> maze = {{'+','+','.','+'}, {'.','.','.','+'}, {'+','+','+','.'}};
    vector<int> entrance = {1, 2};
    int ans = solution_instance.nearestExit(maze, entrance);
    cout << "Answer : " << ans << endl;
    return 0;
}