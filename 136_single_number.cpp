#include<iostream>
#include<vector>

// See properties of XOR funtion.
class Solution {
public:
    int singleNumber(std::vector<int>& nums) {
        int ans = 0;
        // A ^ 0 = A
        // A ^ A = 0
        // (A ^ B) ^ C = A ^ (B ^ C)
        for(const int &num : nums){
            ans ^= num;
        }
        return ans;
    }
};

int main(){
    Solution solution_instance;
    std::vector<int> nums = {4,1,2,1,2};
    std::cout << "Answer: " << solution_instance.singleNumber(nums) << std::endl;
}