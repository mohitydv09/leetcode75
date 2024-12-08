#include<iostream>
#include<vector>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int holding = -prices[0];
        int notHolding = 0;
        for(int i = 1; i < prices.size(); ++i){
            int temp = holding;
            holding = std::max(holding, notHolding - prices[i]);
            notHolding = std::max(notHolding, temp + prices[i]);
        }
        return std::max(holding, notHolding);
    }
};

int main(){
    Solution solution;
    std::vector<int> prices = {7,1,5,3,6,4};
    int answer = solution.maxProfit(prices);
    std::cout << "Answer: " << answer << std::endl;
}