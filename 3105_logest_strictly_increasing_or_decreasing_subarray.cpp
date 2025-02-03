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
    int longestMonotonicSubarray(vector<int>& nums) {
        int maxLen = 1;
        int currMaxLen = 1;
        int currMax = nums[0];

        int minLen = 1;
        int currMinLen = 1;
        int currMin = nums[0];
        for(int i = 1; i < nums.size(); ++i){
            if(nums[i] > currMax){
                currMaxLen++;
                currMax = nums[i];
                maxLen = max(maxLen, currMaxLen);
            }else{
                currMaxLen = 1;
                currMax = nums[i];
            }
            if(nums[i] < currMin){
                currMinLen++;
                currMin = nums[i];
                minLen = max(minLen, currMinLen);
            }else{
                currMinLen = 1;
                currMin = nums[i];
            }
        }
        return max(maxLen, minLen);
    }
};

int main(){
    Solution solution;
    vector<int> input = {1,1,5};
    int answer = solution.longestMonotonicSubarray(input);
    cout << "Answer: " << answer << endl;
}