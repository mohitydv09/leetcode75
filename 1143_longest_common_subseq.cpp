#include<iostream>
#include<string>
#include<vector>

class Solution {
public:
    int longestCommonSubsequence(std::string text1, std::string text2) {
        int rows = text2.size() + 1;
        int cols = text1.size() + 1;
        std::vector<std::vector<int>> grid(rows, std::vector<int>(cols, 0));

        for(int i = 1; i < rows; i++){
            for(int j = 1; j < cols; j++){
                if(text1[j-1] == text2[i-1]){
                    grid[i][j] = grid[i-1][j-1] + 1;
                }else{
                    grid[i][j] = std::max(grid[i][j-1], grid[i-1][j]);
                }
            }
        }
        return grid[rows-1][cols-1];
    }
};

int main(){
    Solution solution_instance;
    std::cout << solution_instance.longestCommonSubsequence("ab", "abc") << std::endl;
}