#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    int numWays(vector<string>& words, string target) {
        int wordLength = words[0].size();
        int targetLength = target.size();
        const int MOD = 1000000007;

        vector<vector<int>> charFreq(wordLength, vector<int>(26,0));
        for(const string& word : words){
            for(int j = 0; j < wordLength; ++j){
                charFreq[j][word[j]-'a']++;
            }
        }
        vector<vector<long>> dp(wordLength + 1, vector<long>(targetLength + 1, 0));
        for(int currWord = 0; currWord <= wordLength; ++currWord){
            dp[currWord][0] = 1;
        }
        for(int currWord = 1; currWord <= wordLength; ++currWord){
            for(int currTarget = 1; currTarget <= targetLength; ++currTarget){
                dp[currWord][currTarget] = dp[currWord-1][currTarget];

                int curPos = target[currTarget - 1] - 'a';
                dp[currWord][currTarget] += (charFreq[currWord-1][curPos] * dp[currWord - 1][currTarget - 1]) % MOD;
                dp[currWord][currTarget] %= MOD;
            }
        }
        return dp[wordLength][targetLength];
    }
};

int main(){
    Solution solution;
    vector<string> words = {"acca","bbbb","caca"};
    int answer = solution.numWays(words, "aba");
    cout << "Answer: " << answer << endl;
}