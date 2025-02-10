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
    long long countBadPairs(vector<int>& nums) {
        unordered_map<int, int> freqMap; // num[i] - i Count
        for(int i = 0; i < nums.size(); ++i){
            freqMap[nums[i] - i]++;
        }
        long long total_pairs = nums.size() * (nums.size() - 1) / 2;
        long long good_pairs = 0;
        for(auto& pair : freqMap){
            good_pairs += pair.second * (pair.second - 1) / 2;
        }
        return total_pairs - good_pairs;
    }
};

int main(){
    Solution solution;
    vector<int> input = {4,1,3,3};
    long long answer = solution.countBadPairs(input);
    cout << "Answer: " << answer << endl;
}