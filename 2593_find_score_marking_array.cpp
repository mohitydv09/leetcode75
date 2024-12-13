#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>

class Solution {
public:
    long long findScore(std::vector<int>& nums) {
        std::vector<std::pair<int,int>> numIdx; //stores the num ans there indices. NUM, Idx
        for(int i = 0; i < nums.size(); ++i){
            numIdx.push_back({nums[i], i});
        }
        std::sort(numIdx.begin(), numIdx.end());

        long long score = 0;
        std::vector<bool> visited(nums.size(), false);
        for(int i = 0; i < numIdx.size(); ++i){
            if(!visited[numIdx[i].second]){
                score += numIdx[i].first;
                visited[numIdx[i].second] = true;
                if (numIdx[i].second - 1 >= 0){
                    visited[numIdx[i].second - 1] = true;
                }
                if (numIdx[i].second + 1 < nums.size()){
                    visited[numIdx[i].second + 1] = true;
                }
            }
        }
        return score;
    }
};

int main(){
    Solution solution;
    std::vector<int> nums = {2,1,3,4,5,2};
    long long answer = solution.findScore(nums);
    std::cout << "Answer: " << answer << std::endl;
}