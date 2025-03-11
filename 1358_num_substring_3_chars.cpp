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
    int numberOfSubstrings(string s) {
        vector<int> freqCount(3, 0);
        int answer = 0;
        int left = 0;
        int right = 0;
        freqCount[s[0] - 'a']++;
        while(right < s.size()){
            if(hasThree(freqCount)){
                answer += s.size() - right;
                freqCount[s[left] - 'a'] = max(freqCount[s[left] - 'a'] - 1, 0);
                left++;
            }else{
                right++;
                if(right < s.size()){
                    freqCount[s[right] - 'a']++;
                }
            }
        }
        return answer;
    }

private:
    bool hasThree(const vector<int>& freqCount){
        return freqCount[0] > 0 && freqCount[1] > 0 && freqCount[2] > 0;
    }
};

int main(){
    Solution solution;
    int answer = solution.numberOfSubstrings("abcabc");
    cout << "Answer: " << answer << endl;
}