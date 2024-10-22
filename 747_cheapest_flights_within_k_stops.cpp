#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<queue>
#include<climits>

/*
Bellman Ford Algorithm
*/

class Solution {
public:
    int findCheapestPrice(int n, std::vector<std::vector<int>>& flights, int src, int dst, int k) {
        std::vector<int> prices(n,INT_MAX);
        prices[src] = 0;

        for(int i = 0; i < k+1; ++i){
            std::vector<int> tempPrice = prices;
            for (auto flight: flights){
                if(prices[flight[0]] == INT_MAX){
                    continue;
                }
                if(prices[flight[0]] + flight[2] < tempPrice[flight[1]]){
                    tempPrice[flight[1]] = prices[flight[0]] + flight[2];
                }
            }
            prices = tempPrice;
        }
        return (prices[dst] == INT_MAX) ? -1 : prices[dst]; 
    }
};

int main(){
    Solution solution;
    int n = 4;
    std::vector<std::vector<int>> flights = {{0,1,100},{1,2,100},{2,0,100},{1,3,600},{2,3,200}};
    int src = 0;
    int dst = 3;
    int k = 1;
    std::cout << "Answer: " << solution.findCheapestPrice(n, flights, src, dst, k) std::endl;
}