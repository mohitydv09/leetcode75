#include<iostream>
#include<vector>

class Solution {
std::vector<std::vector<int>> answer;
public:
    std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        std::vector<int> currCandidates = {};
        dfs(0, candidates, currCandidates, 0, target);
        return answer;
    }

private:
    void dfs(int idx, std::vector<int>& candidates, std::vector<int>& currCandidates, int currSum, int& target){
        if(currSum == target){
            answer.push_back(currCandidates);
            return;
        }
        if(currSum > target || idx >= candidates.size()){
            return;
        }        
        currCandidates.push_back(candidates[idx]);
        currSum += candidates[idx];
        dfs(idx+1, candidates, currCandidates, currSum, target);
        currCandidates.pop_back();
        currSum -= candidates[idx];
        while(idx < candidates.size()-1 && candidates[idx] == candidates[idx+1]){
            idx++;
        }
        dfs(idx+1, candidates, currCandidates, currSum, target);
    }
};

int main(){
    Solution solution;
    std::vector<int> candidates = {2,5,2,1,2};
    int target = 5;
    std::vector<std::vector<int>> answer = solution.combinationSum2(candidates, target);
    for(std::vector<int> item : answer){
        std::cout << std::endl;
        for(int val: item){
            std::cout << val << " ";
        }
    }
    std::cout << std::endl;
}