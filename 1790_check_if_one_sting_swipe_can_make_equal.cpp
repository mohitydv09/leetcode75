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
    bool areAlmostEqual(string s1, string s2) {
        vector<int> idxs;
        for(int i = 0; i < s1.size(); ++i){
            if(s1[i] != s2[i]){
                idxs.push_back(i);
            }
            if(idxs.size() > 2){
                return false;
            }
        }
        if(idxs.size() == 0){
            return true;
        }
        if(idxs.size() == 1){
            return false;
        }
        if(s1[idxs[0]] == s2[idxs[1]] && s1[idxs[1]] == s2[idxs[0]]){
            return true;
        }
        return false;
    }
};

int main(){
    Solution solution;
    vector<int> input = {};
    bool answer = solution.areAlmostEqual("bank", "kanb");
    cout << "Answer: " << answer << endl;
}