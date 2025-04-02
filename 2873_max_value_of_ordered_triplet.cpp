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
        long long answer = 0, imax = 0, dmax = 0;
        for(int k = 0; k < nums.size(); ++k){
            answer = max(answer, dmax * nums[k]);
            dmax = max(dmax, imax - nums[k]);
            imax = max(imax, static_cast<long long>(nums[k]));
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