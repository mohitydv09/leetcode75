#include<iostream>
#include<vector>

class Solution {
public:
    int lengthOfLIS(std::vector<int>& nums) {
        std::vector<int> answer(nums.size(), 1);
        int finalAns = 0;
        for (int i = 0; i < nums.size(); ++i){
            int maxSeq = 0;
            for(int j = 0; j < i; ++j){
                if(nums[j] < nums[i]){
                    maxSeq = std::max(maxSeq, answer[j]);
                }
            }
            answer[i] = maxSeq + 1;
            finalAns = std::max(finalAns, answer[i]);
        }
        return finalAns;
    }
};

int main(){
    Solution solution;
    std::vector<int> nums = {1,3,6,7,9,4,10,5,6};
    std::cout << "Answer: " << solution.lengthOfLIS(nums) << std::endl;
}