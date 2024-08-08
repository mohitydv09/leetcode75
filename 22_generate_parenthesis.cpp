#include<iostream>
#include<vector>
#include<string>

class Solution{
    std::vector<std::string> answer;

public:
    std::vector<std::string> generateParenthesis(int n) {
        std::string currStr = "";
        addChar(currStr, n, 0, 0);
        return answer;
    }
private:
    void addChar(std::string& currStr,int& n, int openCount, int closeCount) {
        if (currStr.size() == 2*n){
            answer.push_back(currStr);
            return;
        }
        if(openCount == closeCount){
            currStr.push_back('(');
            addChar(currStr, n, openCount+1, closeCount);
            currStr.pop_back();
        }else{
            if(openCount < n){
                currStr.push_back('(');
                addChar(currStr, n, openCount+1, closeCount);
                currStr.pop_back();
            }
            if(closeCount < n){
                currStr.push_back(')');
                addChar(currStr, n, openCount, closeCount+1);
                currStr.pop_back();
            }
        }
    };
};

int main(){
    Solution solution;
    std::vector<std::string> answer = solution.generateParenthesis(3);
    std::cout << "Size of answer: "  << answer.size() << std::endl;
    for (std::string str : answer){
        std::cout << str << std::endl;
    }
}