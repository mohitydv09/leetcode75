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
    bool isArraySpecial(vector<int>& nums) {
        for(int i = 0; i < nums.size()-1; i++){
            if((nums[i]%2 == 0 && (nums[i+1]%2 == 0)) || (!(nums[i]%2 == 0) && !(nums[i+1]%2 == 0))){
                return false;
            }
        }
        return true;
    }
};

int main(){
    Solution solution;
    vector<int> input = {2,1,4};
    int answer = solution.isArraySpecial(input);
    cout << "Answer: " << answer << endl;
}