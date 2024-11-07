#include<iostream>
#include<vector>
#include<string>

class Solution {
public:
    int numDistinct(std::string s, std::string t) {
        std::vector<std::vector<unsigned int>> dp(t.size()+1, std::vector<unsigned int>(s.size()+1, 0));
        for(int j = 0; j < dp[0].size(); ++j){
            dp[0][j] = 1;
        }
        for(int i = 1; i < dp.size(); ++i){
            for(int j = 1; j < dp[0].size(); ++j){
                dp[i][j] = (s[j-1] == t[i-1]) ? (dp[i-1][j-1] + dp[i][j-1]) : dp[i][j-1];
            }
        }
        return dp[dp.size()-1][dp[0].size()-1];
    }
};

int main(){
    Solution solution;
    std::cout << "Answer: " << solution.numDistinct("rabbbit", "rabbit") << std::endl;
}