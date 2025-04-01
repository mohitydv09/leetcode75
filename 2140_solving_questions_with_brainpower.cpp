#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<map>
#include<set>
#include<string>
#include<algorithm>

#include "utils.h"

using namespace std;

class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        vector<vector<long long>> dp(2, vector<long long>(questions.size(), 0));
        for(int i = questions.size()-1; i >= 0; --i){
            int score = questions[i][0];
            int bp = questions[i][1];
            //Took this item.
            dp[0][i] = (i + 1 + bp >= questions.size()) ? score : score + max(dp[0][i + 1 + bp], dp[1][i + 1 + bp]);
            dp[1][i] = (i + 1 >= questions.size()) ? 0 : max(dp[0][i+1], dp[1][i+1]);
        }
        return max(dp[0][0], dp[1][0]);
    }
};

int main(){
    Solution solution;
    vector<vector<int>> input = {{1,1}, {2,2}, {3,3}, {4,4}, {5,5}};
    long long answer = solution.mostPoints(input);
    cout << "Answer: " << answer << endl;
}