#include<iostream>
#include<vector>

class Solution{
std::vector<std::vector<int>> answer;
public:
    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target){
        std::vector<int> currCandidates = {};
        dfs(0, currCandidates, 0, candidates, target);
        return answer;
    }

private:
    void dfs(int i,std::vector<int>& currCandidates, int currSum, const std::vector<int>& candidates, const int &target){
        if (currSum == target){
            answer.push_back(currCandidates);
            return;
        }
        if (currSum > target || i >= candidates.size()){
            return;
        }

        currCandidates.push_back(candidates[i]);
        currSum += candidates[i];

        dfs(i, currCandidates, currSum, candidates, target);

        currCandidates.pop_back();
        currSum -= candidates[i];

        dfs(i+1, currCandidates, currSum, candidates, target);
    }
};

int main(){
    Solution solution;
    std::vector<int> candidates = {2,3,6,7};
    int target = 7;
    std::vector<std::vector<int>> answer = solution.combinationSum(candidates, target);
    std::cout << "Answer: " << std::endl;
    for (auto list : answer){
        std::cout << "Item : ";
        for (int item : list){
            std::cout << item << " ";
        }
        std::cout << std::endl;
    }
}