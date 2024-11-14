#include<iostream>
#include<vector>
#include<climits>

class Solution {
public:
    int maxSubArray(std::vector<int>& nums) {
        int maxSum = nums[0];
        int currSum = nums[0];
        for (int i = 1; i < nums.size(); ++i){
            currSum = std::max(currSum+nums[i], nums[i]);
            maxSum = std::max(currSum, maxSum);
        }
        return maxSum;
    }
};

int main() {
    Solution solution;
    std::vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    std::cout << "Answer: " << solution.maxSubArray(nums) << std::endl;
}