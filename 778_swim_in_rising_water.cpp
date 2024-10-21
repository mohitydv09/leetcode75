#include<iostream>
#include<vector>
#include<queue>
#include<unordered_set>

class Solution {
public:
    int swimInWater(std::vector<std::vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        std::priority_queue<std::tuple<int,int,int>, std::vector<std::tuple<int,int,int>>, std::greater<>> frontier; // Min heap will contain height, row, col of a cell in it. We will process the cell with less heights.
        frontier.push({grid[0][0], 0 ,0});
        int maxHeight = grid[0][0];
        std::vector<std::vector<bool>> visited(rows, std::vector<bool>(cols, false));

        while(!frontier.empty()){
            auto[height, row, col] = frontier.top(); frontier.pop();
            std::cout << "Frontier Top: " << height << std::endl;
            maxHeight = std::max(maxHeight, height);
            visited[row][col] = true;
            if(row == rows-1 && col == cols-1){
                return maxHeight;
            }
            // Get neight and add to the frontier.
            if(row+1 < rows && !visited[row+1][col]){frontier.push({grid[row+1][col], row+1, col});};
            if(row-1 >= 0 && !visited[row-1][col]){frontier.push({grid[row-1][col], row-1, col});};
            if(col+1 < cols && !visited[row][col+1]){frontier.push({grid[row][col+1], row, col+1});};
            if(col-1 >= 0 && !visited[row][col-1]){frontier.push({grid[row][col-1], row, col-1});};

        }
        return maxHeight;
    }
};

int main(){
    Solution solution;
    std::vector<std::vector<int>> grid = {{0,1,2,3,4},
                                        {24,23,22,21,5},
                                        {12,13,14,15,16},
                                        {11,17,18,19,20},
                                        {10,9,8,7,6}};
    std::cout << "Answer: " << solution.swimInWater(grid) << std::endl;
}