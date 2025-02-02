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
    bool check(vector<int>& nums) {
        int count = 0;
        if(nums[nums.size()-1] > nums[0]){
            count++;
        }
        for(int i = 0; i < nums.size()-1; ++i){
            if(nums[i] > nums[i+1]){
                count++;
            }
        }
        return (count < 2);
    }
};

int main(){
    Solution solution;
    vector<int> input = {3,4,5,1,2};
    bool answer = solution.check(input);
    cout << "Answer: " << answer << endl;
}