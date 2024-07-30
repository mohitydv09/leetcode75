#include <iostream>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int left = 0;
        int right = 0;
        int maxProfit = 0;
        while(right < prices.size()){
            if(prices[left] < prices[right]){
                int profit = prices[right] - prices[left];
                if(profit > maxProfit){
                    maxProfit = profit;
                }
            }else{
                left=right;
            }
            right++;
        }
        return maxProfit;
    }
};

int main(){
    Solution solution;;
    vector<int> input_ = {7,1,5,3,6,4,-50,0};
    int answer = solution.maxProfit(input_);
    cout << "Answer: " << answer << endl;
}