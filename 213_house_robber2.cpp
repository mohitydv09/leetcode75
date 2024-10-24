#include<iostream>
#include<vector>

class Solution {
public:
    int rob(std::vector<int>& nums) {
        if(nums.size()==1){return nums[0];}
        if(nums.size()==2){return std::max(nums[0], nums[1]);}

        int secondLast = nums[0];
        int last = std::max(nums[0], nums[1]);
        for(int i = 2; i < nums.size()-1; ++i){
            int temp = last;
            last = std::max(nums[i] + secondLast, last);
            secondLast = temp;
        }

        int secondLast2 = nums[1];
        int last2 = std::max(nums[1], nums[2]);
        for(int i = 3; i < nums.size(); ++i){
            int temp = last2;
            last2 = std::max(nums[i]+secondLast2, last2);
            secondLast2 = temp;
        }
        return std::max(last, last2);
    }
};

int main(){
    Solution sol_instance;
    std::vector<int> nums = {1,2,3,1};
    std::cout << sol_instance.rob(nums) << std::endl;
}