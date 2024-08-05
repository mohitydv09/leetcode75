#include <iostream>
#include <stack>

class Solution {
public:
    bool isValid(std::string s) {
        std::stack<char> stk;
        for (int i = 0; i < s.size(); ++i){
            if(stk.size() == 0){
                stk.push(s[i]);
                continue;
            }
            if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
                stk.push(s[i]);
            }else{
                if(s[i] == ')' && stk.top() == '('){
                    stk.pop();
                }else if(s[i] == ']' && stk.top() == '['){
                    stk.pop();
                }else if(s[i] == '}' && stk.top() == '{'){
                    stk.pop();
                }else{
                    return false;
                }
            }
        }
        if(stk.size() == 0){
            return true;
        }else{
            return false;
        }
    }
};

int main(){
    Solution solution;
    std::string s = "]";
    bool answer = solution.isValid(s);
    std::cout << "Answer: " << answer << std::endl;
}