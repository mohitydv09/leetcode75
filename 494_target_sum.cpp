#include<iostream>
#include<vector>
#include<numeric>

class Solution {
public:
    int findTargetSumWays(std::vector<int>& nums, int target) {
        // Next time rewrite this with memoization.
        int totalSum = std::accumulate(nums.begin(), nums.end(), 0);
        if(std::abs(target) > std::abs(totalSum)){
            return 0;
        }

        //Initialize DP
        std::vector<int> prev(2*totalSum + 1, 0);
        prev[totalSum] = 1;
        for(const int& num : nums){
            std::vector<int> dp(2*totalSum + 1, 0);
            for(int i = 0; i < dp.size(); ++i){
                if(i-num >= 0){
                    dp[i] += prev[i - num];
                }
                if(i + num < dp.size()){
                    dp[i] += prev[i + num];
                }                
            }
            prev = dp;
        }
        return prev[totalSum + target];
    }
};


int main() {
    Solution solution;
    std::vector<int> nums = {1};
    std::cout << "Answer: " << solution.findTargetSumWays(nums, 2) << std::endl;
}