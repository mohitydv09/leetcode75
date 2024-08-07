#include<iostream>
#include<stack>
#include<string>
#include<vector>

class Solution {
public:
    int evalRPN(std::vector<std::string>& tokens){
        std::stack<int> stk;
        for (const std::string& st : tokens){
            if(st == "+" || st == "-" || st == "/" || st == "*"){
                int second = stk.top(); stk.pop();
                int first = stk.top(); stk.pop();
                int result;
                switch (st[0]){
                    case '+' : result = first + second; break;
                    case '-' : result = first - second; break;
                    case '*' : result = first * second; break;
                    case '/' : result = first / second; break;
                }
                stk.push(result);
            }else{
                stk.push(stoi(st));
            }
        }
        return stk.top();
    }
};

int main(){
    Solution solution;
    std::vector<std::string> tokens = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    int answer = solution.evalRPN(tokens);
    std::cout << "answer : " << answer << std::endl;
}

// '+', '-', '*', and '/'