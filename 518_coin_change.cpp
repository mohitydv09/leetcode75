#include<iostream>
#include<vector>
#include<climits>

class Solution {
public:
    int change(int amount, std::vector<int>& coins) {
        std::vector<std::vector<int>> combinations(coins.size(), std::vector<int>(amount+1, 1));

        for (int i = 0; i < combinations.size(); ++i){
            for(int j = 1; j < combinations[0].size(); ++j){
                int top = (i >= 1) ? combinations[i-1][j] : 0;
                int left = (j-coins[i] >= 0) ? combinations[i][j-coins[i]] : 0;
                combinations[i][j] = (top > INT_MAX - left) ? 0 :top + left; // Just to pass the idiot test case.
            }
        }
        return combinations[combinations.size()-1][combinations[0].size()-1];
    }
};

int main(){
    Solution solution;
    std::vector<int> coins = {1,2,5};
    std::cout << "Answer: " << solution.change(4681, coins) << std::endl;
}