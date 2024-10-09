#include<iostream>
#include<vector>

class Solution {
private:
    std::vector<std::vector<bool>> visited;
    int maxArea;
    int currArea;
public:
    int maxAreaOfIsland(std::vector<std::vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int count = 0;
        visited = std::vector<std::vector<bool>>(rows, std::vector<bool>(cols, false));
        for (int row = 0; row < rows; ++row){
            for(int col = 0; col < cols; ++col){
                if(grid[row][col] == 1 && visited[row][col] == false){
                    currArea++;
                    search(row, col, grid);
                    if(currArea > maxArea){
                        maxArea = currArea;
                    }
                    currArea = 0;
                }
            }
        }
        return maxArea;
    }
private:
    void search(int row, int col, const std::vector<std::vector<int>>& grid){
        if(row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size()){
            return;
        }
        if(grid[row][col] == 0 || visited[row][col]){
            return;
        }
        currArea++;
        visited[row][col] = true;
        search(row + 1, col, grid);
        search(row - 1, col, grid);
        search(row, col + 1, grid);
        search(row, col - 1, grid);
    }
};

int main(){
    Solution solution;
    std::vector<std::vector<int>> grid = {{1,1,0,0,0},
                                        {1,1,0,0,0},
                                        {0,0,1,0,0},
                                        {0,0,0,1,1}};
    int answer = solution.maxAreaOfIsland(grid);
    std::cout << "Answer: " << answer << std::endl;
}