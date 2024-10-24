#include<iostream>
#include<vector>

class Solution {
public:
    int rob(std::vector<int>& nums) {
        if(nums.size()==1){return nums[0];}

        int secondLast = nums[0];
        int last = std::max(nums[0], nums[1]);
        for(int i = 2; i < nums.size(); ++i){
            int temp = last;
            last = std::max(nums[i] + secondLast, last);
            secondLast = temp;
        }
        return last;
    }
};

int main(){
    Solution sol_instance;
    std::vector<int> nums = {1,2,3,1};
    std::cout << sol_instance.rob(nums) << std::endl;
}