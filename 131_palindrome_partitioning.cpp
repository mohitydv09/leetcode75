#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

class Solution {
std::vector<std::vector<std::string>> answer;
public:
    std::vector<std::vector<std::string>> partition(std::string s) {
        std::vector<std::string> currPart;
        dfs(0, s.size(), currPart, s);
        return answer;
    }

private:
    void dfs(int i, int j, std::vector<std::string>& currPart, const std::string &s){
        if(i >= s.size()){
            answer.push_back(currPart);
            return;
        }
        for(int k = i; k < j; ++k){
            std::string newString = s.substr(i, k-i+1);
            if(isPalindrome(newString)){
                currPart.push_back(newString);
                dfs(k+1, j, currPart, s);
                currPart.pop_back();
            }
        }
    }

    bool isPalindrome(const std::string &s){
        std::string revStr = s;
        std::reverse(revStr.begin(), revStr.end());
        return revStr == s;
    }
};

int main(){
    Solution solution;
    std::string s = "AAB";
    std::vector<std::vector<std::string>> answer = solution.partition(s);
    std::cout << "Answer: " << std::endl;
    for(auto item : answer){
        for(auto str : item){
            std::cout << str << " ";
        }
        std::cout << std::endl;
    }
}