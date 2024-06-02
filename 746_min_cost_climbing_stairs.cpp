#include<iostream>

using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> min_cost(cost.size(),0);
        min_cost[0] = cost[0];
        min_cost[1] = cost[1];
        for(int i = 2; i < min_cost.size(); i++){
            min_cost[i] = cost[i] + min(min_cost[i-1], min_cost[i-2]);
        }
        return min(min_cost[min_cost.size()-1], min_cost[min_cost.size()-2]);
    }
};

int main(){
    Solution solution_instance;
    vector<int> cost= {1,100,1,1,1,100,1,1,100,1};
    cout << "Ans : " << solution_instance.minCostClimbingStairs(cost) << endl;
}