#include<iostream>
#include<string>
#include<vector>

class Solution {
public:
    bool wordBreak(std::string s, std::vector<std::string>& wordDict) {
        std::vector<bool> answer(s.size()+1, false);
        answer[s.size()] = true;
        for(int i = s.size()-1; i >= 0; --i){
            for(std::string word : wordDict){
                if(i + word.size() <= s.size() && s.substr(i,word.size()) == word){
                    answer[i] = answer[i + word.size()];
                }
                if(answer[i]){break;}
            }
        }
        return answer[0];
    }
};

int main(){
    Solution solution;
    std::string s = "leetcode";
    std::vector<std::string> wordDict = {"leet","code"};
    std::cout << "Answer: " << solution.wordBreak(s, wordDict) << std::endl;
}