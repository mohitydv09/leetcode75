#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<map>
#include<set>
#include<string>
#include<algorithm>
#include<numeric>

#include "utils.h"

using namespace std;

class Solution {
public:
    int minimumLength(string s) {
        int charIdx[26] = {0};
        for(int i = 0; i < s.size(); ++i){
            charIdx[s[i] - 'a']++;
            if(charIdx[s[i] - 'a'] > 2){
                charIdx[s[i] - 'a'] = 1;
            }
        }
        int answer = 0;
        for(const int& ct : charIdx){
            answer += ct;
        }
        return answer;
    }
};

int main(){
    Solution solution;
    vector<int> input = {};
    int answer = solution.minimumLength("abaacbcbb");
    cout << "Answer: " << answer << endl;
}