#include<iostream>
#include<vector>
#include<climits>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        std::vector<std::vector<int>> profits(2, std::vector<int>(prices.size(), 0));
        profits[0][0] = 0;          // Not-Holding        
        profits[1][0] = -prices[0]; // Holding
        
        for (int j = 1; j < prices.size(); ++j){
            std::cout << "J : " << j << std::endl;
            profits[0][j] = std::max(profits[0][j-1], profits[1][j-1] + prices[j]); //Not holding
            profits[1][j] = std::max(profits[1][j-1], ((j > 1) ? profits[0][j-2] : 0) - prices[j]); //Holding 
        }
        return profits[0][prices.size()-1];
    }
};

int main(){
    Solution solution;
    std::vector<int> prices = {1,2,3,0,2};
    std::cout << "Answer: " << solution.maxProfit(prices) << std::endl;
}