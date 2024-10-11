#include<iostream>
#include<vector>

class Solution {
public:
    std::vector<std::vector<int>> pacificAtlantic(std::vector<std::vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();
        std::vector<std::vector<int>> pacific(rows, std::vector<int>(cols, false));
        std::vector<std::vector<int>> atlantic(rows, std::vector<int>(cols, false));

        for(int col = 0; col < cols; ++col){
            bfs(0, col, pacific, heights[0][col], heights);
            bfs(rows-1, col, atlantic, heights[rows-1][col], heights);
        }
        for(int row = 0; row < rows; ++row){
            bfs(row, 0, pacific, heights[row][0], heights);
            bfs(row, cols-1, atlantic, heights[row][cols-1], heights);

        }
        std::vector<std::vector<int>> answer;
        for (int row = 0; row < rows; ++row){
            for(int col = 0; col < cols; ++col){
                if(pacific[row][col] && atlantic[row][col]){
                    answer.push_back({row, col});
                }
            }
        }
        return answer;
    }

private:
    void bfs(int row, int col, std::vector<std::vector<int>>& visited, int prevHeight, std::vector<std::vector<int>>& heights){
        if(row < 0 || row >= visited.size() || col < 0 || col >= visited[0].size() || 
        heights[row][col] < prevHeight ||
        visited[row][col]){
            return;
        }
        visited[row][col] = true;
        bfs(row + 1, col, visited, heights[row][col], heights);
        bfs(row - 1, col, visited, heights[row][col], heights);
        bfs(row, col + 1, visited, heights[row][col], heights);
        bfs(row, col - 1, visited, heights[row][col], heights);
    }
};

int main(){
    Solution solution;
    std::vector<std::vector<int>> heights = {{1,2,2,3,5},{3,2,3,4,4},{2,4,5,3,1},{6,7,1,4,5},{5,1,1,2,4}};
    std::vector<std::vector<int>> answer = solution.pacificAtlantic(heights);
    std::cout << "Answer: " << std::endl;
    for(auto point: answer){
        std::cout << point[0] << " " << point[1] << std::endl;
    }
}