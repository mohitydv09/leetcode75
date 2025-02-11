#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<map>
#include<set>
#include<string>
#include<cctype>
#include<algorithm>

#include "utils.h"

using namespace std;

class Solution {
public:
    string removeOccurrences(string s, string part) {
        int n = part.size();
        vector<char> stringStack;
        for(int i = 0; i < s.size(); ++i){
            stringStack.push_back(s[i]);
            if(stringStack.size() >= n){
                string currStr;
                for(auto it = stringStack.cend()-n; it != stringStack.cend(); ++it){
                    currStr.push_back(*it);
                }
                if(currStr == part){
                    //remove last n items
                    stringStack.resize(stringStack.size()-n);
                }
            }
        }
        string answer;
        for(int i = 0; i < stringStack.size(); ++i){
            answer.push_back(stringStack[i]);
        }
        return answer;
    }
};

int main(){
    Solution solution;
    string answer = solution.removeOccurrences("daabcbaabcbc", "abc");
    cout << "Answer: " << answer << endl;
}