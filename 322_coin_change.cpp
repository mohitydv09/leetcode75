#include<iostream>
#include<vector>
#include<climits>

class Solution {
public:
    int coinChange(std::vector<int>& coins, int amount) {
        if(amount == 0){return 0;}
        std::vector<int> minCoins(amount+1, INT_MAX);
        for(int coin : coins){
            if(coin < minCoins.size()){
                minCoins[coin] = 1;
            }
        }
        for(int i = 1; i < amount+1; ++i){
            if(minCoins[i] != 1){
                int currMin = INT_MAX;
                for(int j = 0; j < coins.size(); ++j){
                    if(i - coins[j] > 0 && minCoins[i-coins[j]] != -1){
                        currMin = std::min(currMin, minCoins[i-coins[j]]);
                    }
                }
                minCoins[i] = (currMin == INT_MAX) ? INT_MAX : currMin + 1;
            }
        }
        return (minCoins[amount] == INT_MAX) ? -1 : minCoins[amount];
    }
};

int main(){
    Solution solution;
    std::vector<int> coins = {2};
    int amount = 1;
    std::cout << "Answer: " << solution.coinChange(coins, amount) << std::endl;
}