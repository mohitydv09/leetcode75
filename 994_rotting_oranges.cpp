#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <set>
#include <tuple>

using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int numRows = grid.size();
        int numCols = grid[0].size();

        vector<vector<bool>> visited(numRows, vector<bool>(numCols, false));
        queue<pair<int,int>> frontier;

        // Traverse the Grid and find the Rotten Oranges.
        for (int row = 0; row < numRows; row++){
            for (int col = 0; col < numCols; col++){
                if (grid[row][col] == 2){
                    cout << "Rotten Found at : " << row << col << endl;
                    frontier.push({row, col});
                    visited[row][col] = true;
                }else if(grid[row][col] == 0){
                    visited[row][col] = true;
                }
            }
        }

        int directions[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};

        int time = 0;
        while(!frontier.empty()){
            int frontierSize = frontier.size();
            cout << "Frontier Size Was : " << frontierSize << endl;
            for (int i = 0; i < frontierSize; i++){
                auto [currRow, currCol] = frontier.front();
                frontier.pop();
                for(auto dir : directions){
                    int newRow = currRow + dir[0];
                    int newCol = currCol + dir[1];
                    if(newRow >= 0 && newRow < numRows && newCol >= 0 && newCol < numCols && !visited[newRow][newCol] && grid[newRow][newCol] == 1){
                        frontier.push({newRow, newCol});
                        visited[newRow][newCol] = true;
                    }
                }
            }
            if(!frontier.empty()){
                time++;
            }
        }
        for (int i = 0; i < numRows; i++){
            for(int j = 0; j < numCols; j++){
                if(visited[i][j] == false){
                    return -1;
                }
            }
        }
        return time;
    }
};

int main(){
    Solution solution_instance;
    vector<vector<int>> input_grid = {{2,1,1}, {1,1,0}, {0,1,1}};
    int ans = solution_instance.orangesRotting(input_grid);
    cout << "Answer : " << ans << endl;
    return 0;
}