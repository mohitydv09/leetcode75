#include<iostream>
#include<vector>

class Solution{
public:
    int search(std::vector<int>& nums, int target){
        int left = 0;
        int right = nums.size()-1;
        int mid;
        while(left <= right){
            mid = (left+right)/2;
            if(nums[mid] == target){
                return mid;
            }

            if(nums[left] <= nums[mid]){
                if (target > nums[mid] || target < nums[left]){
                    left = mid + 1;
                }else{
                    right = mid - 1;
                }
            }else{
                if (target < nums[mid] || target > nums[right]){
                    right = mid - 1;
                }else{
                    left = mid + 1;
                }
            }
        }
        return -1;
    }   
};

int main() {
    Solution solution;
    std::vector<int> nums = {3,4,5,6,7,8,9,1,2};
    int target = 1;
    // std::vector<int> nums = {2,1};
    int ans = solution.search(nums, target);
    std::cout << "Answer: " << ans << std::endl;
}