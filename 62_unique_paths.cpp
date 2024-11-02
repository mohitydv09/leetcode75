#include<iostream>
#include<vector>

class Solution {
public:
    int uniquePaths(int m, int n) {
        std::vector<std::vector<int>> grid(m, std::vector<int>(n,1));
        for(int i = 1; i < m; ++i){
            for(int j = 1; j < n; ++j){
                grid[i][j] = grid[i-1][j] + grid[i][j-1];
            }
        }
        return grid[m-1][n-1];
    }
};

int main(){
    Solution solution_instance;
    std::cout << "Ans : " << solution_instance.uniquePaths(3,4) << std::endl;
}