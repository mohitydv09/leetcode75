#include<iostream>
#include<vector>

class Solution {
public:
    int minCostClimbingStairs(std::vector<int>& cost){
        int secondLast = cost[0];
        int last = cost[1];
        for(int i = 2; i < cost.size(); ++i){
            int temp = last;
            last = std::min(secondLast + cost[i], last + cost[i]);
            secondLast = temp;
        }
        return std::min(last, secondLast);
    }
};

int main(){
    Solution solution_instance;
    std::vector<int> cost = {1,100,1,1,1,100,1,1,100,1};
    // std::vector<int> cost = {10,15,20};
    std::cout << "Answer: " << solution_instance.minCostClimbingStairs(cost) << std::endl;
}