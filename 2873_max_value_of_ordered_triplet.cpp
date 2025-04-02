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
    long long maximumTripletValue(vector<int>& nums) {
        long long answer = 0;
        for (int i = 0; i < nums.size()-2; ++i){
            for (int j = i + 1; j < nums.size()-1; ++j){
                for (int k = j + 1; k < nums.size(); ++k){
                    long long val =  1LL * (nums[i] - nums[j]) * nums[k];
                    answer = max(answer, val);
                }
            }
        }
        return answer;
    }
};

int main(){
    Solution solution;
    vector<int> input = {12,6,1,2,7};
    long long answer = solution.maximumTripletValue(input);
    cout << "Answer: " << answer << endl;
}