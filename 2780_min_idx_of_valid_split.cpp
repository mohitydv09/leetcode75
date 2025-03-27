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
    int minimumIndex(vector<int>& nums) {
        unordered_map<int, int> freqMap;
        for(int& num : nums){
            freqMap[num]++;
        }
        int maxVal = 0;
        int maxFreq = 0;
        for(const auto& item : freqMap){
            if(item.second > maxFreq){
                maxFreq = item.second;
                maxVal = item.first;
            }
        }
        int freqFirst = 0;
        int freqRest = maxFreq;
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] == maxVal){
                freqFirst++;
                freqRest--;
            }
            cout << "I: " << i << " " << freqFirst << "  " << freqRest << endl;
            // cout << "front: " << i/2 
            if(freqFirst > i/2 && freqRest > (nums.size() - i - 1)/2){
                return i;
            }
        }
        return -1;
    }
};

int main(){
    Solution solution;
    vector<int> input = {3,3,3,3,7,2,2};
    int answer = solution.minimumIndex(input);
    cout << "Answer: " << answer << endl;
}