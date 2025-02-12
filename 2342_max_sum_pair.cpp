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
    int maximumSum(vector<int>& nums) {
        unordered_map<int, int> sum2max; // Stores the current max nums[i] with this sum of digits.
        int maxVal = -1;
        for(int i = 0; i < nums.size(); ++i){
            int sumOfDigits = sumDigits(nums[i]);
            if(sum2max.find(sumOfDigits) != sum2max.end()){
                maxVal = max(maxVal, sum2max[sumOfDigits] + nums[i]);
                sum2max[sumOfDigits] = max(sum2max[sumOfDigits], nums[i]);
            }else{
                // first time encountering this item.
                sum2max[sumOfDigits] = nums[i];
            }
        }
        return maxVal;
    }

private:
    int sumDigits(int a){
        int sumDigit = 0;
        while(a > 0){
            sumDigit += a%10;
            a /= 10;
        }
        return sumDigit;
    }
};

int main(){
    Solution solution;
    vector<int> input = {10,12,19,14};
    int answer = solution.maximumSum(input);
    cout << "Answer: " << answer << endl;
}