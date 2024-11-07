#include<iostream>
#include<vector>

class Solution {
public:
    int longestIncreasingPath(std::vector<std::vector<int>>& matrix) {
        std::vector<std::vector<int>> longPath(matrix.size(),std::vector<int>(matrix[0].size(), 0));
        int answer = 0;
        for(int i = 0; i < matrix.size(); ++i){
            for(int j = 0; j < matrix[0].size(); ++j){
                answer = std::max(answer, dfs(i, j, matrix, longPath));
            }
        }
        std::cout << std::endl;
        for(auto item : longPath){
            for(auto item2: item){
                std::cout << item2 << " "; 
            }
            std::cout << std::endl;
        }
        return answer;
    }

private:
    int dfs(int i, int j, std::vector<std::vector<int>>& matrix, std::vector<std::vector<int>>& longPath){
        if(longPath[i][j] > 0){return longPath[i][j];}
        int top = (i-1 >= 0)                    ? ((matrix[i-1][j] > matrix[i][j]) ? dfs(i-1, j, matrix, longPath) : 0) : 0;
        int bottom = (i+1 < matrix.size())      ? ((matrix[i+1][j] > matrix[i][j]) ? dfs(i+1, j, matrix, longPath) : 0) : 0;
        int left = (j-1 >= 0)                   ? ((matrix[i][j-1] > matrix[i][j]) ? dfs(i, j-1, matrix, longPath) : 0) : 0;
        int right = (j+1 < matrix[0].size())    ? ((matrix[i][j+1] > matrix[i][j]) ? dfs(i, j+1, matrix, longPath) : 0) : 0;
        longPath[i][j] = 1 + std::max(top, std::max(bottom, std::max(left, right)));
        return longPath[i][j];
    }
};

int main(){
    Solution solution;
    std::vector<std::vector<int>> matrix = {{9,9,4},{6,6,8},{2,1,1}};
    std::cout << "Answer: " << solution.longestIncreasingPath(matrix) << std::endl;
}