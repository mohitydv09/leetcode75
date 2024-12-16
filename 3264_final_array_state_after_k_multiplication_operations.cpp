#include<iostream>
#include<vector>
#include<queue>

class Solution {
public:
    std::vector<int> getFinalState(std::vector<int>& nums, int k, int multiplier) {
        std::priority_queue<std::pair<int,int>, std::vector<std::pair<int,int>>, std::greater<std::pair<int, int>>> minHeap; //item, index
        for(int i = 0; i < nums.size(); ++i){
            minHeap.emplace(nums[i], i);
        }
        for(int i = 0; i < k; ++i){
            auto minVal = minHeap.top(); minHeap.pop();
            nums[minVal.second] *= multiplier;
            minHeap.emplace(nums[minVal.second], minVal.second);
        }
        return nums;
    }
};

int main(){
    Solution solution;
    std::vector<int> nums = {2,1,3,5,6};
    std::vector<int> answer = solution.getFinalState(nums, 5, 2);
    std::cout << "Answer: " << std::endl;
    for (const int& item : answer){
        std::cout << item << " ";
    }
    std::cout << std::endl;
}