#include<iostream>
#include<vector>
#include<cmath>

class Solution {
public:
    std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix) {
        std::vector<int> answer;
        int startRow = 0, startCol = 0;
        int endRow = matrix.size(), endCol = matrix[0].size();
        while(startRow < endRow && startCol < endCol){
            for(int col = startCol; col < endCol; ++col){
                answer.push_back(matrix[startRow][col]);
            }
            startRow++;
            for(int row = startRow; row < endRow; ++row){
                answer.push_back(matrix[row][endCol-1]);
            }
            endCol--;
            if (!(startCol < endCol && startRow < endRow)){
                break;
            }
            for(int col = endCol-1; col >= startCol; --col){
                answer.push_back(matrix[endRow-1][col]);
            }
            endRow--;
            for(int row = endRow-1; row >= startRow; --row){
                answer.push_back(matrix[row][startCol]);
            }
            startCol++;
        }
        return answer;
    }
};

int main(){
    Solution solution;
    std::vector<std::vector<int>> matrix = {{1,2,3,4},{5,6,7,8},{9,10,11,12}}; 
    std::vector<int> answer = solution.spiralOrder(matrix);
    std::cout << "Answer: ";
    for (int item : answer){
        std::cout << item << " ";
    }
    std::cout << std::endl;
}