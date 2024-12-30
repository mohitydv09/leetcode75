#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high+1, 0);
        dp[zero] += 1; dp[one] += 1;
        int answer = 0;
        for(int i = 1; i < dp.size(); ++i){

                dp[i] += (i - zero >=0) ? dp[i-zero]%1000000007 : 0;
                dp[i] += (i - one >= 0) ? dp[i-one]%1000000007 : 0;
                if(i >= low){
                    answer = dp[i]%1000000007;
                }
        }
        return answer%1000000007;
    }
};

int main(){
    Solution solution;
    int answer = solution.countGoodStrings(2, 3, 1, 2);
    cout << "Answer: " << answer << endl;
}