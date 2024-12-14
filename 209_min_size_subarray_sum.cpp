#include<iostream>
#include<vector>
#include<climits>
#include<numeric>

class Solution {
public:
    int minSubArrayLen(int target, std::vector<int>& nums) {
        int left = 0, right = 0;
        int currSum = nums[0];
        int minWin = INT_MAX;
        while(right < nums.size()){
            std::cout << "left: " << left << " right: " << right << std::endl;
            if(currSum >= target){
                minWin = std::min(minWin, right-left + 1);
                if(minWin == 1){return 1;}
                currSum -= nums[left];
                left++;
            }else{
                right++;
                if (right < nums.size()){
                    currSum += nums[right];
                }
            }
        }
        return (minWin == INT_MAX) ? 0 : minWin;
    }
};

int main(){
    Solution solution;
    std::vector<int> nums = {2,3,1,2,4,3};
    int answer = solution.minSubArrayLen(4, nums);
    std::cout << "Answer: " << answer << std::endl;
}