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
    int countPrefixSuffixPairs(vector<string>& words) {
        int answer = 0;
        for(int i = 0; i < words.size(); ++i){
            for(int j = i + 1; j < words.size(); ++j){
                answer += isPrefixAndSuffix(words[i], words[j]);
            }
        }
        return answer;
    }

private:
    bool isPrefixAndSuffix(string str1, string str2){
        if((str1.size() > str2.size()) || (str1 != str2.substr(0,str1.size())) || (str1 != str2.substr(str2.size()-str1.size(), str1.size()))){
            return false;
        }
        return true;
    }
};

int main(){
    Solution solution;
    vector<string> input = {"a","aba","ababa","aa"};
    int answer = solution.countPrefixSuffixPairs(input);
    cout << "Answer: " << answer << endl;
}