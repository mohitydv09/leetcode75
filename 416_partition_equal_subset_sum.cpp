#include<iostream>
#include<vector>
#include<numeric>
#include<unordered_set>

class Solution {
public:
    bool canPartition(std::vector<int>& nums) {
        int sum_of_nums = std::accumulate(nums.begin(), nums.end(),0);
        if(sum_of_nums % 2 != 0){return false;}
        int target = sum_of_nums/2;
        std::unordered_set<int> possibleSums;
        possibleSums.emplace(0);
        
        for(int i = 0; i < nums.size(); ++i){
            std::unordered_set<int> temp = possibleSums;
            for (auto it = temp.begin(); it != temp.end(); ++it){
                if(*it < target){
                    possibleSums.emplace(*it + nums[i]);
                }
                if(*it == target){
                    return true;
                }
            }
        }
        return false;
    }
};

int main(){
    Solution solution;
    std::vector<int> nums = {1,5,11,5};
    std::cout << "Answer: " << solution.canPartition(nums) << std::endl;
}