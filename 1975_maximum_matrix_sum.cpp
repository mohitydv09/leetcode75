#include<iostream>
#include<vector>
#include<climits>

class Solution {
public:
    long long maxMatrixSum(std::vector<std::vector<int>>& matrix) {
        int minEle = INT_MAX;
        long long totalSum = 0;
        int isNeg = 1;
        for (auto row : matrix){
            for(auto ele : row){
                totalSum += std::abs(ele);
                minEle = std::min(minEle, std::abs(ele));
                if (ele < 0){
                    isNeg*= -1;
                }
            }
        }
        return (isNeg == 1) ? totalSum : totalSum - 2*minEle;
    }
};

int main(){
    Solution solution;
    std::vector<std::vector<int>> matrix = {{1,2,3},{-1,-2,-3},{1,2,3}};
    long long answer = solution.maxMatrixSum(matrix);
    std::cout << "Answer: " << answer << std::endl;
}