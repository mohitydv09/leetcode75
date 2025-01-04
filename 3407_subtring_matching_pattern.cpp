#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>

#include "utils.h"

class Solution {
public:
    bool hasMatch(string s, string p) {
        int idx = 0;
        while(p[idx] != '*'){
            idx++;
        }
        string leftSub = p.substr(0, idx);
        string rightSub = p.substr(idx+1, p.size());
        int i = 0;
        while(s.substr(i, leftSub.size()) != leftSub){
            if(i >= s.size()){
                return false;
            }
            i++;
        }
        i += leftSub.size();
        while(s.substr(i, rightSub.size()) != rightSub){
            if(i >= s.size()){
                return false;
            }
            i++;
        }
        return true;
    }
};

int main(){
    Solution solution;
    vector<int> input = {};
    bool answer = solution.hasMatch("leetcode", "ee*e");
    cout << "Answer: " << answer << endl;
}