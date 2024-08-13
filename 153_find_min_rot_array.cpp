#include<iostream>
#include<vector>

class Solution{
public:
    int findMin(std::vector<int>& nums){
        int left = 0;
        int right = nums.size()-1;
        int mid;
        int minNum = nums[0];
        while(left < right){
            mid = (left+right)/2;
            if(nums[left] <= nums[right]){
                minNum =  (nums[left] < minNum) ? nums[left] : minNum;
                return minNum;
            }else if(nums[mid] >= nums[left] && nums[mid] > nums[right]){
                left = mid + 1;
                minNum =  (nums[left] < minNum) ? nums[left] : minNum;
            }else if(nums[mid] <= nums[right] && nums[mid] < nums[left]){
                minNum =  (nums[mid] < minNum) ? nums[mid] : minNum;
                right = mid - 1;
            }
        }
        return minNum;
    }   
};

int main() {
    Solution solution;
    // std::vector<int> nums = {3,4,5,6,7,8,9,1,2};
    std::vector<int> nums = {2,1};
    int ans = solution.findMin(nums);
    std::cout << "Answer: " << ans << std::endl;
}