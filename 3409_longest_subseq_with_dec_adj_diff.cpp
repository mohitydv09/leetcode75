#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<map>
#include<set>
#include<climits>

#include "utils.h"

using namespace std;

class Solution {
unordered_map<string, int> hashTable;

public:
    int longestSubsequence(vector<int>& nums) {
        return dfs(0, -1, INT_MAX, nums);
    }

private:
    int dfs(int idx, int prev, int prevDiff, vector<int>& nums){
        if(idx >= nums.size()){
            return 0;
        }

        string hashKey = to_string(idx) + ',' + to_string(prev) + ',' + to_string(prevDiff);
        if(hashTable.find(hashKey) != hashTable.end()){
            return hashTable[hashKey];
        }

        int notTaken = dfs(idx+1, prev, prevDiff, nums);

        int taken = 0;
        if(prev == -1 || prevDiff >= abs(nums[idx] - prev)){
            prevDiff = (prev == -1) ? INT_MAX : abs(nums[idx] - prev);
            taken = 1 + dfs(idx+1, nums[idx], prevDiff, nums);
        }
        return hashTable[hashKey] = max(taken, notTaken);
    }
};

int main(){
    Solution solution;
    vector<int> input = {68, 83, 52, 70, 52};
    int answer = solution.longestSubsequence(input);
    cout << "Answer: " << answer << endl;
}