#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<map>
#include<set>
#include<string>
#include<algorithm>

#include "utils.h"

using namespace std;

class Solution {
    public:
        int subsetXORSum(vector<int>& nums) {
            int currSum = 0, answer = 0;
            dfs(0, currSum, nums, answer);
            return answer;
        }
    
    private:
        void dfs(int idx, int& currSum, vector<int>& nums, int& answer){
            if(idx == nums.size()){
                answer += currSum;
                return;
            }
            dfs(idx + 1, currSum, nums, answer);
            currSum ^= nums[idx];
            dfs(idx + 1, currSum, nums, answer);
        }
    };

int main(){
    Solution solution;
    vector<int> input = {5,1,6};
    int answer = solution.subsetXORSum(input);
    cout << "Answer: " << answer << endl;
}