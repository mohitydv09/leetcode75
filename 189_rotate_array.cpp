#include<iostream>
#include<vector>
#include<algorithm>

class Solution {
public:
    void rotate(std::vector<int>& nums, int k) {
        k %= nums.size();
        std::reverse(nums.begin(), nums.end());
        std::reverse(nums.begin(), nums.begin() + k);
        std::reverse(nums.begin() + k, nums.end());

        std::cout << "Final Nums: " ;
        for(int num : nums){
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
};

int main(){
    Solution solution;
    std::vector<int> nums = {1,2,3,4,5,6,7};
    solution.rotate(nums, 3);
}