#include<iostream>
#include<vector>

class Solution {
public:
    int canCompleteCircuit(std::vector<int>& gas, std::vector<int>& cost) {
        int idx = 0;
        int currSum = 0;
        int totalSum = 0;
        for (int i = 0; i < gas.size(); ++i){
            currSum += gas[i] - cost[i];
            totalSum += gas[i] - cost[i];
            if(currSum < 0){
                currSum = 0;
                idx = i + 1;
            }
        }
        return (totalSum < 0) ? -1 : idx;
    }
};

int main(){
    Solution solution;
    std::vector<int> gas = {1,2,3,4,5};
    std::vector<int> cost = {3,4,5,1,2};
    std::cout << "Answer: " << solution.canCompleteCircuit(gas, cost) << std::endl;
}