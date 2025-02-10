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
    string clearDigits(string s) {
        deque<char> chars;
        for(int i = 0; i < s.size(); ++i){
            if(isdigit(s[i])){
                chars.pop_back();
            }else{
                chars.push_back(s[i]);
            }
        }
        string answer;
        while(!chars.empty()){
            answer.push_back(chars.front());
            chars.pop_front();
        }
        return answer;
    }
};

int main(){
    Solution solution;
    string answer = solution.clearDigits("abc4");
    cout << "Answer: " << answer << endl;
}