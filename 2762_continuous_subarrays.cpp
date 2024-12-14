#include<iostream>
#include<vector>
#include<map>

class Solution {
public:
    long long continuousSubarrays(std::vector<int>& nums) {
        int left = 0, right = 0;
        long long answer = 0;
        std::map<int, int> hashMap;
        while(right < nums.size()){
            hashMap[nums[right]]++;
            while(hashMap.rbegin()->first - hashMap.begin()->first > 2){
                hashMap[nums[left]]--;
                if(hashMap[nums[left]] == 0){
                    hashMap.erase(nums[left]);
                }
                left++;
            }
            answer += right - left + 1;
            right++;
        }
        return answer;
    }
};

int main(){
    Solution solution;
    std::vector<int> nums = {5,4,2,4};
    long long answer = solution.continuousSubarrays(nums);
    std::cout << "Answer: " << answer << std::endl;
}