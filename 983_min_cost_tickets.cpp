#include<iostream>
#include<vector>
#include<climits>

using namespace std;

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(days[days.size()-1]+1, -1);
        dp[0] = 0;
        for(const int& day : days){
            dp[day] = 0;
        }
        for(int i = 1; i < dp.size(); ++i){
            if(dp[i] == -1){
                //Not required.
                dp[i] = dp[i-1];
            }else{
                int one = dp[i-1] + costs[0];
                int two = (i - 7 >= 0) ? dp[i-7] + costs[1] : dp[0] + costs[1];
                int three = (i - 30 >= 0) ? dp[i-30] + costs[2] : dp[0] + costs[2];
                dp[i] = min(one, min(two, three));
            }
            cout << "dp " << i << " : " << dp[i] << endl;
        }
        return dp[dp.size()-1];
    };
};

int main(){
    Solution solution;
    vector<int> days = {1,4,6,7,8,20};
    vector<int> costs = {7,2,15};
    int answer = solution.mincostTickets(days, costs);
    cout << "Answer: " << answer << endl;
}