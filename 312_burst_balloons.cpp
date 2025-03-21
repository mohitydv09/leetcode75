#include<iostream>
#include<vector>

class Solution {
public:
    int maxCoins(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> extended_nums(n+2, 1);
        for (int i = 0; i < n; ++i){
            extended_nums[i+1] = nums[i];
        }

        std::vector<std::vector<int>> dp(n+2, std::vector<int>(n+2, 0));
        for (int length = 2; length <= n + 1; ++length){
            for (int left = 0; left <= n + 1 - length; ++left){
                int right = left + length;
                for (int k = left + 1; k < right; ++k){
                    dp[left][right] = std::max(dp[left][right],
                                            dp[left][k] + dp[k][right] + extended_nums[left]*extended_nums[k]*extended_nums[right]);
                }
            }
        }
        return dp[0][n+1];
    }
};

int main() {
    Solution solution;
    std::vector<int> nums = {3,1,5,8};
    std::cout << "Answer: " << solution.maxCoins(nums) << std::endl;
}