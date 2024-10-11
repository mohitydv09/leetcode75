#include <iostream>
#include <vector>
#include <queue>

class Solution {
public:
    int orangesRotting(std::vector<std::vector<int>>& grid) {
        int numRows = grid.size();
        int numCols = grid[0].size();

        std::vector<std::vector<bool>> visited(numRows, std::vector<bool>(numCols, false));
        std::queue<std::pair<int,int>> frontier;

        // Add Rotten oranges to frontier.
        for (int row = 0; row < numRows; ++row){
            for (int col = 0; col < numCols; ++col){
                if (grid[row][col] == 2){
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
            for (int i = 0; i < frontierSize; ++i){
                auto [currRow, currCol] = frontier.front(); frontier.pop();
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
    std::vector<std::vector<int>> input_grid = {{2,1,1}, {1,1,0}, {0,1,1}};
    int ans = solution_instance.orangesRotting(input_grid);
    std::cout << "Answer : " << ans << std::endl;
    return 0;
}