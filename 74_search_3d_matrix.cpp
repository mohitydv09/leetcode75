#include<iostream>
#include<vector>

class Solution {
public:
    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
        int leftRow = 0;
        int rightRow = matrix.size()-1;
        while(leftRow < rightRow){
            int mid = (leftRow+rightRow)/2;
            if(matrix[mid][0] < target){
                leftRow = mid + 1;
            }else if(matrix[mid][0] > target){
                rightRow = mid - 1;
            }else{
                return true;
            }
        }
        if (matrix[leftRow][0] > target && leftRow > 0){
            leftRow--;
        }
        int leftCol = 0;
        int rightCol = matrix[leftRow].size() - 1;
        while(leftCol <= rightCol){
            int mid = (leftCol + rightCol)/2;
            if(matrix[leftRow][mid] < target){
                leftCol = mid + 1;
            }else if(matrix[leftRow][mid] > target){
                rightCol = mid - 1;
            }else{
                return true;
            }
        }
        return false;
    }
};

int main() {
    Solution solution;
    // std::vector<std::vector<int>> nums = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    std::vector<std::vector<int>> nums = {{1},{3}};
    int target = 1;
    int ans = solution.searchMatrix(nums, target);
    std::cout << "Answer: " << ans << std::endl;
}