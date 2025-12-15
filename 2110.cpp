#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long totalPeriods = 0;
        long long currPeriod = 1;

        for (int i = 1; i < prices.size(); ++i){
            if (prices[i-1] - prices[i] == 1){
                currPeriod++;
            }else{
                totalPeriods += currPeriod * (currPeriod + 1) / 2;
                currPeriod = 1;
            }
        }
        totalPeriods += currPeriod * (currPeriod + 1) / 2;
        return totalPeriods;
    }
};

int main(){
    Solution solution;
    vector<int> input = {3,2,1,4};
    long long answer = solution.getDescentPeriods(input);
    cout << "Answer: " << answer << endl;
}