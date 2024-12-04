#include<iostream>
#include<vector>

class Solution {
public:
    int missingNumber(std::vector<int>& nums) {
        int n = nums.size() + 1;
        int answer = 0;
        for (int i = 0; i < n; ++i){
            answer ^= i;
        }
        for(const int& num : nums){
            answer ^= num;
        }
        return answer;
    }
};

int main(){
    Solution solution;
    std::vector<int> nums = {9,6,4,2,3,5,7,0,1};
    int answer = solution.missingNumber(nums);
    std::cout << "Answer: " << answer << std::endl;
}