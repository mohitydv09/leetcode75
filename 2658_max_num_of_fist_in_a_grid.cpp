#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<map>
#include<set>
#include<string>
#include<algorithm>

#include "utils.h"

using namespace std;

class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int numRows = grid.size();
        int numCols = grid[0].size();
        vector<vector<bool>> visited(numRows, vector<bool> (numCols, false));
        int answer = 0;
        for(int row = 0; row < numRows; ++row){
            for(int col = 0; col < numCols; ++col){
                if(!visited[row][col] && grid[row][col] != 0){
                    answer = max(answer, dfs(row, col, grid, visited));
                }
            }
        }
        return answer;
    }
private:
    int dfs(int row, int col, vector<vector<int>>& grid, vector<vector<bool>>& visited){
        if(visited[row][col]){
            return 0;
        }
        visited[row][col] = true;
        int top = (row > 0 && !visited[row-1][col] && grid[row-1][col] != 0) ? dfs(row-1, col, grid, visited) : 0;
        int bottom = (row+1 < grid.size() && !visited[row+1][col] && grid[row+1][col] != 0) ? dfs(row+1, col, grid, visited) : 0;
        int right = (col+1 < grid[0].size() && !visited[row][col+1] && grid[row][col+1] != 0) ? dfs(row, col+1, grid, visited) : 0;
        int left = (col > 0 && !visited[row][col-1] && grid[row][col-1] != 0) ? dfs(row, col-1, grid, visited) : 0;
        return top + bottom + right + left + grid[row][col];
    }
};

int main(){
    Solution solution;
    vector<vector<int>> input = {{0,4}}; //{{0,2,1,0},{4,0,0,3},{1,0,0,4},{0,3,2,0}};
    int answer = solution.findMaxFish(input);
    cout << "Answer: " << answer << endl;
}