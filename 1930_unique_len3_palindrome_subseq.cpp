#include<iostream>
#include<vector>
#include<numeric>
#include<unordered_map>
#include<unordered_set>

using namespace std;

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<pair<int, int>> startEndChar(26, {-1,-1});
        for(int i = 0; i < s.size(); ++i){
            if(startEndChar[s[i]-'a'].first == -1){
                startEndChar[s[i]-'a'].first = i;
            }
            startEndChar[s[i]-'a'].second = i;
        }
        int answer = 0;
        for(int i = 0; i < 26; ++i){
            int start = startEndChar[i].first;
            int end = startEndChar[i].second;
            if(end > start + 1){
                bool isBetween[26] = {false};
                for(int k = start + 1; k < end; ++k){
                    if(isBetween[s[k]-'a'] == false){
                        isBetween[s[k]-'a'] = true;
                        answer++;
                    }
                }

            }
        }
        return answer;
    }
};

int main (){
    Solution solution;
    int answer = solution.countPalindromicSubsequence("bbcbaba");
    cout << "Answer: " << answer << endl;
}