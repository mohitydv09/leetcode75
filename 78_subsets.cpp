#include<iostream>
#include<vector>

class Solution {
public:
    std::vector<std::vector<int>> subsets(std::vector<int>& nums){
        std::vector<std::vector<int>> answer;
        for(int num : nums){
            int currLen = answer.size();
            for (int i = 0; i < currLen; ++i){
                std::vector<int> newItem = answer[i];
                newItem.push_back(num);
                answer.push_back(newItem);
            }
            answer.push_back({num});
        }
        answer.push_back({});
        return answer;
    }
};

int main(){
    Solution solution;
    std::vector<int> nums = {1,2,3};
    std::vector<std::vector<int>> answer = solution.subsets(nums);
    for(std::vector<int> item : answer){
        std::cout << std::endl;
        for(int val: item){
            std::cout << val << " ";
        }
    }
}