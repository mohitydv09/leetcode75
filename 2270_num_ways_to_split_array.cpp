#include<iostream>
#include<vector>
#include<numeric>

using namespace std;

class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int answer = 0;
        long long sumNums = accumulate(nums.begin(), nums.end(), static_cast<long long>(0));
        long long currSum = 0;
        for(int i = 0; i < nums.size()-1; ++i){
            currSum += nums[i];
            if(currSum >= sumNums - currSum){
                answer++;
            }
        }
        return answer;
    }
};

int main (){
    Solution solution;
    vector<int> nums = {2,3,1,0};
    int answer = solution.waysToSplitArray(nums);
    cout << "Answer: " << answer << endl;
}