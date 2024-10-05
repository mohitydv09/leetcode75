#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>

class Solution {
std::vector<std::string> answer;
std::unordered_map<char,std::string> digit2chars = {
    {'2', "abc"},
    {'3', "def"},
    {'4', "ghi"},
    {'5', "jkl"},
    {'6', "mno"},
    {'7', "pqrs"},
    {'8', "tuv"},
    {'9', "wxyz"}
};

public:
    std::vector<std::string> letterCombinations(std::string digits) {
        if(digits.size() == 0){
            return answer;
        }
        std::string currString;
        backTrack(0, digits, currString);
        return answer;
    }

private:
    void backTrack(int idx, std::string &digits, std::string &currString){
        if(idx == digits.size()){
            answer.push_back(currString);
            return;
        }
        std::string characters = digit2chars[digits[idx]];
        for(int i = 0; i < characters.size(); ++i){
            currString.push_back(characters[i]);
            backTrack(idx + 1, digits, currString);
            currString.pop_back();
        }
        return;
    }
};

int main(){
    Solution solution;
    std::string digits = "";
    std::vector<std::string> ans = solution.letterCombinations(digits);
    std::cout << "Answer: " ;
    for(std::string item : ans){
        std::cout << " " << item;
    }
    std::cout << std::endl;
    return 0;
}