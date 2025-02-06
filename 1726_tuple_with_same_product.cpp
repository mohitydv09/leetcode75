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
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> freqMap;
        for(int i = 0; i < nums.size()-1; ++i){
            for(int j = i+1; j < nums.size(); ++j){
                freqMap[nums[i]*nums[j]]++;
            }
        }
        int answer = 0;
        for(auto& p : freqMap){
            if(p.second > 1){
                answer += p.second*(p.second - 1) / 2;
            }
        }
        return answer*8;
    }
};

int main(){
    Solution solution;
    vector<int> input = {2,3,4,6};
    int answer = solution.tupleSameProduct(input);
    cout << "Answer: " << answer << endl;
}