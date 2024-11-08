#include<iostream>
#include<string>
#include<vector>

class Solution {
public:
    int minDistance(std::string word1, std::string word2) {
        std::vector<std::vector<int>> dp(word1.size()+1,std::vector<int>(word2.size()+1,0));
        for(int i = 0; i < dp.size(); ++i){
            dp[i][0] = i;
        }
        for(int j = 0; j < dp[0].size(); ++j){
            dp[0][j] = j;
        }

        for(int i = 1; i < dp.size(); ++i){
            for(int j = 1; j < dp[0].size(); ++j){
                if(word1[i-1] != word2[j-1]){
                    dp[i][j] = 1 + std::min(dp[i-1][j] , std::min(dp[i][j-1], dp[i-1][j-1]));
                }else{
                    dp[i][j] = dp[i-1][j-1];
                }
            }

        }
        std::cout << "DP : " << std::endl;
        for (auto row : dp){
            for(int item : row){
                std::cout << item << " ";
            }
            std::cout << std::endl;
        }
        return dp[dp.size()-1][dp[0].size()-1];
    }
};

int main(){
    Solution solution_instance;
    // string word1 = "horse";
    // string word1 = "zoologicoarchaeologist";
    // ststring word2 = "ros"; 
    // string word2 = "zoogeologist";
    std::cout << "Answer: " << solution_instance.minDistance("horse", "ros") << std::endl;
}