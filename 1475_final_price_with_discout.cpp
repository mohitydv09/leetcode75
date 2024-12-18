#include<iostream>
#include<vector>

class Solution {
public:
    std::vector<int> finalPrices(std::vector<int>& prices) {
        prices.push_back(0);
        for(int i = 0; i < prices.size()-1; ++i){
            int j = i+1;
            while(prices[i] < prices[j]){
                j++;
            }
            prices[i] -= prices[j];
        }
        prices.pop_back();
        return prices;
    }
};

int main(){
    Solution solution;
    std::vector<int> prices = {8,4,6,2,3};
    std::vector<int> answer = solution.finalPrices(prices);
    std::cout << "Answer: ";
    for(int& item : answer){
        std::cout << item << " ";
    }
    std::cout << std::endl;
}