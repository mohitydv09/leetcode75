#include<iostream>
#include<vector>
#include<unordered_set>

class Solution {
public:
    void setZeroes(std::vector<std::vector<int>>& matrix) {
        int firstRow = 0;
        int firstCol = 0;
        for(int i = 0; i < matrix.size(); ++i){
            for(int j = 0; j < matrix[0].size(); ++j){
                if(matrix[i][j] == 0){
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                    if(i == 0){
                        firstRow = 1;
                    }
                    if(j == 0){
                        firstCol = 1;
                    }
                }
            }
        }
        for(int i = 1; i < matrix.size(); ++i){
            for(int j = 1; j < matrix[0].size(); ++j){
                if(matrix[0][j] == 0 || matrix[i][0] == 0){
                    matrix[i][j] = 0;
                }
            }
        }
        if(firstCol == 1){
            for(int i = 0; i < matrix.size(); ++i){
                matrix[i][0] = 0;
            }
        }
        if(firstRow == 1){
            for(int j = 0; j < matrix[0].size(); ++j){
                matrix[0][j] = 0;
            }
        }
    }
};

int main(){
    Solution solution;
    std::vector<std::vector<int>> matrix = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    solution.setZeroes(matrix);
}