#include<iostream>
#include<string>
#include<vector>

class Solution {
public:
    bool isInterleave(std::string s1, std::string s2, std::string s3) {
        std::vector<std::vector<bool>> dp(s2.size()+1, std::vector<bool>(s1.size()+1, false));
        if(s1.size() + s2.size() != s3.size()){
            return false;
        }
        dp[0][0] = true;
        for(int i = 1; i < dp.size(); ++i){
            dp[i][0] = (dp[i-1][0]) ? (s2[i-1] == s3[i-1]) : false;
        }
        for(int j = 1; j < dp[0].size(); ++j){
            dp[0][j] = (dp[0][j-1]) ? (s1[j-1] == s3[j-1]) : false;
        }
        for(int i = 1; i < dp.size(); ++i){
            for(int j = 1; j < dp[0].size(); ++j){
                bool top = (dp[i-1][j]) ? (s2[i-1] == s3[i+j-1]) : false;
                bool left = (dp[i][j-1]) ? (s1[j-1] == s3[i+j-1]) : false;
                dp[i][j] = top || left;
            }
        }
        for (auto item : dp){
            std::cout << std::endl;
            for (auto i : item){
                std::cout << i  << " ";
            }
        }
        return dp[dp.size()-1][dp[0].size()-1];
    }
};

int main(){
    Solution solution;
    std::cout << "Answer: " << solution.isInterleave("aabcc", "dbbca", "aadbbcbcac") << std::endl;
}