#include<iostream>
#include<vector>

class Solution {
public:
    void rotate(std::vector<std::vector<int>>& matrix) {
        int n = matrix.size();

        for (int i = 0; i < n/2; i++){
            for (int j = i; j < n-i-1; ++j){
                int temp = matrix[j][n-i-1];
                matrix[j][n-i-1] = matrix[i][j];

                int temp2 = matrix[n-i-1][n-j-1];
                matrix[n-i-1][n-j-1] = temp;

                int temp3 = matrix[n-1-j][i];
                matrix[n-1-j][i] = temp2;

                matrix[i][j] = temp3;
            }
        }
        for (auto row : matrix){
            for (int item : row){
                std::cout << item << " ";
            }
            std::cout << std::endl;
        }
    }
};

int main(){
    Solution solution;
    std::vector<std::vector<int>> matrix = {{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};
    solution.rotate(matrix);
}