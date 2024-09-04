#include<iostream>
#include<vector>

class Solution {
public:
    int findDuplicate(std::vector<int>& nums) {
        int fast = 0;
        int slow = 0;
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow != fast);

        int slow2 = 0;
        do{
            slow2 = nums[slow2];
            slow = nums[slow];
        }while(slow != slow2);
        return slow;
    }
};

int main() {
    Solution solution;
    std::vector<int> nums = {1,3,4,2,2};
    int answer = solution.findDuplicate(nums);
    std::cout << "Answer: " << answer << std::endl;
}