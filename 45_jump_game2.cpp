#include<iostream>
#include<vector>
#include<climits>

class Solution {
public:
    int jump(std::vector<int>& nums) {
        int minJump = 0;
        int left = 0;
        int right = 0;
        while(right < nums.size()-1){
            int reach = 0;
            for (int i = left; i < right + 1; ++i){
                reach = std::max(reach, i + nums[i]);
            }
            left = right + 1;
            right = reach;
            minJump++;
        }
        return minJump;
    }
};

int main() {
    Solution solution;
    std::vector<int> nums = {7,0,9,6,9,6,1,7,9,0,1,2,9,0,3};
    std::cout << "Answer: " << solution.jump(nums) << std::endl;
}