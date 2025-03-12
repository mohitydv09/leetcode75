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
    int maximumCount(vector<int>& nums) {
        int neg = 0;
        while(neg < nums.size() && nums[neg] < 0){
            neg++;
        }
        int zero = neg;
        while(zero < nums.size() && nums[zero] <= 0){
            zero++;
        }
        int pos = nums.size() - zero;
        return max(neg, pos);
    }
};

int main(){
    Solution solution;
    vector<int> input = {-3,-2,-1,0,0,1,2};
    vector<int> zeros = {0,0,0,0,0};
    int answer = solution.maximumCount(zeros);
    cout << "Answer: " << answer << endl;
}