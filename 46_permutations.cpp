#include<iostream>
#include<vector>

class Solution {
std::vector<std::vector<int>> answer;

public:
    std::vector<std::vector<int>> permute(std::vector<int>& nums){
        std::vector<bool> options(nums.size(), true);
        int optionsNum = nums.size();
        std::vector<int> currPerm = {};
        dfs(optionsNum, options, nums, currPerm);
        return answer;
    }

private:
    void dfs(int &optionsNum, std::vector<bool>& options, std::vector<int>& nums, std::vector<int>& currPerm){
        if (optionsNum == 0){
            answer.push_back(currPerm);
            return;
        }

        for(int i = 0; i < options.size(); ++i){
            if(options[i]){
                currPerm.push_back(nums[i]);
                optionsNum--;
                options[i] = false;
                dfs(optionsNum, options, nums, currPerm);
                currPerm.pop_back();
                optionsNum++;
                options[i] = true;
            }
        }
    }
};

int main(){
    Solution solution;
    std::vector<int> candidates = {1,2};
    std::vector<std::vector<int>> answer = solution.permute(candidates);
    std::cout << "Answer: " << std::endl;
    for (auto list : answer){
        std::cout << "Item : ";
        for (int item : list){
            std::cout << item << " ";
        }
        std::cout << std::endl;
    }
}