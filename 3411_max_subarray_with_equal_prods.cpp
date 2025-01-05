#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<map>
#include<set>
#include<string>
#include<numeric>

#include "utils.h"

using namespace std;

class Solution {
public:
    int maxLength(vector<int>& nums) {
        int maxLen = 1;
        for(int i = 0; i < nums.size(); ++i){
            long long currGCD = nums[i];
            long long currLCM = nums[i];
            long long currProd = nums[i];
            for(int j = i+1; j < nums.size(); ++j){
                currGCD = gcd(currGCD, nums[j]);
                currLCM = lcm(currLCM, nums[j]);
                currProd *= nums[j];
                if(currProd == currGCD * currLCM){
                    maxLen = max(maxLen, j - i + 1);
                }else{
                    break;
                }
            }
        }
        return maxLen;
    }
};

int main(){
    Solution solution;
    vector<int> input = {1,2,1,2,1,1,1};
    int answer = solution.maxLength(input);
    cout << "Answer: " << answer << endl;
}