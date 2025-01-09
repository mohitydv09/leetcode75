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
    int prefixCount(vector<string>& words, string pref) {
        int answer = 0;
        for(const auto& word: words){
            if(word.size() >= pref.size() && word.substr(0, pref.size()) == pref){
                answer++;
            }
        }
        return answer;
    }
};

int main(){
    Solution solution;
    vector<string> input = {"pay","attention","practice","attend"};
    int answer = solution.prefixCount(input, "at");
    cout << "Answer: " << answer << endl;
}