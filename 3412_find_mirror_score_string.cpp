#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<map>
#include<set>
#include<string>
#include<stack>

#include "utils.h"

using namespace std;

class Solution {
public:
    long long calculateScore(string s) {
        vector<stack<int>> occ(26);
        occ[s[0]-'a'].push(0);
        long long score = 0;
        for(int i = 1; i < s.size(); ++i){
            int mirrorIdx = 25 - (s[i] - 'a');
            if(!occ[mirrorIdx].empty()){
                int prevOcc = occ[mirrorIdx].top(); occ[mirrorIdx].pop();
                score += i - prevOcc;
            }else{
                occ[s[i] - 'a'].push(i);
            }
        }
        return score;
    }
};

int main(){
    Solution solution;
    vector<int> input = {};
    long long answer = solution.calculateScore("abcdef");
    cout << "Answer: " << answer << endl;
}