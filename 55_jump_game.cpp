#include<iostream>
#include<vector>

class Solution {
public:
    bool canJump(std::vector<int>& nums) {
        int canReach = 0;
        for(int i = 0; i < nums.size(); ++i){
            if(i > canReach){
                return false;
            }
            canReach = std::max(canReach, i + nums[i]);
            if (canReach >= nums.size()){
                return true;
            }
        }
        return false;
    }
};

int main() {
    Solution solution;
    std::vector<int> nums = {3,2,1,0,4};
    std::cout << "Answer: " << solution.canJump(nums) << std::endl;
}