#include<iostream>

using namespace std;

class Solution{
public:
    int maxProfit(vector<int>& prices, int fee){

        vector<int> free(prices.size(),0);
        vector<int> holding(prices.size(),0);
        holding[0] = -prices[0];

        for(int i = 1; i < prices.size(); i++){
            free[i] = max(free[i-1], prices[i] + holding[i-1] - fee);
            holding[i] = max(holding[i-1], free[i-1] - prices[i]);
        }
        
        cout << "Free : "; 
        for(int item : free){
            cout << item << " ";
        }
        cout << endl;

        cout << "Holding : "; 
        for(int item : holding){
            cout << item << " ";
        }
        cout << endl;

        return free.back();
    }
};

int main(){
    Solution solution_instance;
    vector<int> prices = {1,3,2,8,4,9};
    int fee = 2;
    cout << solution_instance.maxProfit(prices, fee) << endl;
}