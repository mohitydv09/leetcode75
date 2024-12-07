#include<iostream>
#include<vector>
#include<unordered_map>

class Solution{
public:
    int majorityElement(std::vector<int>& nums){
        std::unordered_map<int, int> hashMap;
        for(const int& num : nums){
            hashMap[num]++;
            if(hashMap[num] > nums.size()/2){
                return num;
            }
        }
        return -1;
    }
};

int main(){
    Solution solution;
    std::vector<int> nums = {1,2,2,2,2,2,2,1,1,1,1};
    int answer = solution.majorityElement(nums);
    std::cout << "Answer: " << answer << std::endl;
}