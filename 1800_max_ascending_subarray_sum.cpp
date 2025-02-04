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
    int maxAscendingSum(vector<int>& nums) {
        int maxSum = nums[0];
        int currSum = nums[0];
        for(int i = 1; i < nums.size(); ++i){
            if(nums[i] > nums[i-1]){
                currSum += nums[i];
                maxSum = max(maxSum, currSum);
            }else{
                currSum = nums[i];
            }
        }        
        return maxSum;
    }
};

int main(){
    Solution solution;
    vector<int> input = {10,20,30,5,10,50};
    int answer = solution.maxAscendingSum(input);
    cout << "Answer: " << answer << endl;
}