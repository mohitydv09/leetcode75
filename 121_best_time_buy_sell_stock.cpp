#include <iostream>
#include <vector>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int currMin = prices[0];
        int maxProfit = 0;
        for (int i = 0; i < prices.size(); ++i){
            currMin = std::min(currMin, prices[i]);
            maxProfit = std::max(maxProfit, prices[i]-currMin);
        }
        return maxProfit;
    }
};

int main(){
    Solution solution;;
    std::vector<int> prices = {7,1,5,3,6,4,-0,0};
    int answer = solution.maxProfit(prices);
    std::cout << "Answer: " << answer << std::endl;
}