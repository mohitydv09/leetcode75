#include<iostream>
#include<string>
#include<stack>
#include<variant>


class Solution {
public:
    int calculate(std::string s) {
        int answer = 0;
        int sign = 1;
        std::stack<std::pair<int,int>> myStack;
        for(int i = 0; i < s.size(); ++i){
            if(isdigit(s[i])){
                int currAns = 0;
                while(i < s.size() && isdigit(s[i])){
                    currAns = currAns * 10 + (s[i] - '0');
                    i++;
                }
                i--;
                answer += currAns * sign;
                sign = 1;
            }else if(s[i] == '('){
                myStack.push({answer, sign});
                answer = 0;
                sign = 1;
            }else if(s[i] == ')'){
                answer = myStack.top().first + (myStack.top().second * answer);
                myStack.pop();
            }else if(s[i] == '-'){
                sign = -1 * sign;
            }
        }
        return answer;
    }
};

int main(){
    Solution solution;
    int answer = solution.calculate("(1+(4+5+2)-3)+ (6+8)");
    std::cout << "Answer: " << answer << std::endl;
}