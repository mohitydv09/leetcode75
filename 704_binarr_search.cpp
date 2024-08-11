#include<iostream>
#include<vector>

class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        while(left <= right){
            int mid = (left+right)/2;
            if(nums[mid] < target){
                left = mid + 1;
            }else if(nums[mid] > target){
                right = mid - 1;
            }else{
                return mid;
            }
        }
        return -1;
    }
};

int main() {
    Solution solution;
    std::vector<int> nums = {-1,0,3,5,9,12};
    int target = -1;
    int ans = solution.search(nums, target);
    std::cout << "Answer: " << ans << std::endl;
}