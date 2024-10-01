#include<iostream>
#include<vector>

class Solution {
std::vector<std::vector<int>> answer;
public:
    std::vector<std::vector<int>> subsetsWithDup(std::vector<int>& nums){
        std::vector<int> currSet;
        std::sort(nums.begin(), nums.end());
        dfs(0, nums, currSet);
        return answer;
    }
private:
    void dfs(int idx, std::vector<int>& nums, std::vector<int>& currSet){
        if(idx >= nums.size()){
            answer.push_back(currSet);
            return;
        }
        currSet.push_back(nums[idx]);
        dfs(idx+1, nums, currSet);
        currSet.pop_back();

        while(idx < nums.size()-1 && nums[idx] == nums[idx+1]){
            idx++;
        }
        dfs(idx+1, nums, currSet);
    }
};

int main(){
    Solution solution;
    std::vector<int> nums = {1,2,2};
    std::vector<std::vector<int>> answer = solution.subsetsWithDup(nums);
    for(std::vector<int> item : answer){
        std::cout << std::endl;
        for(int val: item){
            std::cout << val << " ";
        }
    }
    std::cout << std::endl;
}