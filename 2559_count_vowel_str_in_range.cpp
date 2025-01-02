#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include "utils.h"

using namespace std;

class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> vowelTillHere(words.size()+1,0);
        int count = 0;
        for(int i = 0; i < words.size(); ++i){
            if((words[i][0] == 'a' || words[i][0] == 'e' || words[i][0] == 'i' || words[i][0] == 'o' || words[i][0] == 'u') && (words[i][words[i].size()-1] == 'a' || words[i][words[i].size()-1] == 'e' || words[i][words[i].size()-1] == 'i' || words[i][words[i].size()-1] == 'o' || words[i][words[i].size()-1] == 'u')){
                count++;
            }
            vowelTillHere[i+1] = count;
        }

        vector<int> answer(queries.size(),0);
        for(int i = 0; i < queries.size(); ++i){
            answer[i] = vowelTillHere[queries[i][1]+1] - vowelTillHere[queries[i][0]];
        }
        return answer;
    }
};

int main(){
    Solution solution;
    vector<string> words = {"aba","bcb","ece","aa","e"};
    vector<vector<int>> queries = {{0,2}, {1,4}, {1,1}};
    vector<int> answer = solution.vowelStrings(words, queries);
    cout << "Answer: ";
    printVector(answer);
}