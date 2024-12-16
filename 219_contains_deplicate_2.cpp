#include<iostream>
#include<vector>
#include<unordered_map>

class Solution {
public:
    bool containsNearbyDuplicate(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> hashMap; // Item, latest indice
        for (int i = 0; i < nums.size(); ++i){
            if(hashMap.find(nums[i]) != hashMap.end() && i - hashMap[nums[i]] <= k){
                return true;
            }
            hashMap[nums[i]] = i;
        }
        return false;
    }
};

int main(){
    Solution solution;
    std::vector<int> nums = {1,2,3,1};
    bool answer = solution.containsNearbyDuplicate(nums, 3);
    std::cout << "Answer: " << answer << std::endl;
}