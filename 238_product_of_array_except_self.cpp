#include <iostream>
#include <string>
#include <vector>
#include <sstream>

class Solution {
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums) {
        std::vector<int> answer(nums.size(),1);
        for(int i = 1; i < nums.size(); ++i){
            answer[i] = answer[i-1]*nums[i-1];
        }
        int backProd = 1;
        for(int i = nums.size()-2; i >= 0; --i){
            backProd *= nums[i+1];
            answer[i] *= backProd;
        }
        return answer;
    }
};

int main(){
    Solution solution_instance;
    std::vector<int> nums = {-1};
    std::vector<int> answer = solution_instance.productExceptSelf(nums);
    return 0;
}