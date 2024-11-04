#include<iostream>
#include<vector>
#include<numeric>

class Solution {
public:
    int findTargetSumWays(std::vector<int>& nums, int target) {
        int totalSum = std::accumulate(nums.begin(), nums.end(), 0);

        if ((target + totalSum) % 2 != 0 || totalSum + target < 0){
            return 0;
        }
        int newTarget = (target + totalSum) / 2;

        std::vector<int> dp(newTarget + 1, 0);
        dp[0] = 1;

        for (auto num : nums){
            for (int j = newTarget; j > num-1; --j){
                dp[j] += dp[j - num];
            }
        }
        return dp[newTarget];
    }
};

int main() {
    Solution solution;
    std::vector<int> nums = {1,1,1,1,1};
    std::cout << "Answer: " << solution.findTargetSumWays(nums, 3) << std::endl;
}