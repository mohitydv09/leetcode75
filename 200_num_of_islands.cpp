#include<iostream>
#include<vector>

class Solution {
private:
    std::vector<std::vector<bool>> visited;
public:
    int numIslands(std::vector<std::vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int count = 0;
        visited = std::vector<std::vector<bool>>(rows, std::vector<bool>(cols, false));
        for (int row = 0; row < rows; ++row){
            for(int col = 0; col < cols; ++col){
                if(grid[row][col] == '1' && visited[row][col] == false){
                    count++;
                    search(row, col, grid);
                }
            }
        }
        return count;
    }
private:
    void search(int row, int col, const std::vector<std::vector<char>>& grid){
        if(row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size()){
            return;
        }
        if(grid[row][col] == '0' || visited[row][col]){
            return;
        }
        visited[row][col] = true;
        search(row + 1, col, grid);
        search(row - 1, col, grid);
        search(row, col + 1, grid);
        search(row, col - 1, grid);
    }
};

int main(){
    Solution solution;
    std::vector<std::vector<char>> grid = {{'1','1','0','0','0'},
                                            {'1','1','0','0','0'},
                                            {'0','0','1','0','0'},
                                            {'0','0','0','1','1'}};
    int answer = solution.numIslands(grid);
    std::cout << "Answer: " << answer << std::endl;
}