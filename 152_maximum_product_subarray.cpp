#include<iostream>
#include<vector>

class Solution {
public:
    int maxProduct(std::vector<int>& nums) {
        int prevMin = nums[0];
        int prevMax = nums[0];
        int currMin;
        int currMax;
        int maxProd = prevMax;
        for(int i = 1; i < nums.size(); ++i){
            if(nums[i] == 0){
                //do something.
                currMin = 0;
                currMax = 0;
            }else if(nums[i] > 0){
                //Positive
                currMin = std::min(nums[i], prevMin*nums[i]);
                currMax = std::max(nums[i], prevMax*nums[i]);
            }else{
                //negetive
                currMin = std::min(nums[i], prevMax*nums[i]);
                currMax = std::max(nums[i], prevMin*nums[i]);
            }
            maxProd = std::max(maxProd, currMax);
            prevMax = currMax;
            prevMin = currMin;
        }
        return maxProd;
    }
};

int main(){
    Solution solution;
    std::vector<int> nums = {2,3,-2,4};
    std::cout << "Answer: " << solution.maxProduct(nums) << std::endl;
}