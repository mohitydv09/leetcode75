#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<map>
#include<set>
#include<stack>
#include<string>
#include<algorithm>

#include "utils.h"

using namespace std;

class Solution {
public:
    bool canBeValid(string s, string locked) {
        if(s.size()%2 != 0){
            return false;
        }
        stack<int> any; // Unlocked items
        stack<int> open; // Locked Open Items
        for(int i = 0; i < s.size(); ++i){
            if(locked[i] == '0'){
                any.push(i);
            }else{
                if(s[i] == '('){
                    open.push(i);
                }else{
                    if(!open.empty()){
                        open.pop();
                    }else if(!any.empty()){
                        any.pop();
                    }else{
                        return false;
                    }
                }
            }
        }
        while(!open.empty() && !any.empty() && open.top() < any.top()){
            open.pop();
            any.pop();
        }
        if(!open.empty()){
            return false;
        }
        return true;
    }
};

int main(){
    Solution solution;
    bool answer = solution.canBeValid(")(", "00");
    cout << "Answer: " << answer << endl;
}