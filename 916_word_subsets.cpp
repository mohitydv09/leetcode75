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
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        // Process the words 2 into a single vector.
        int word2arr[26] = {0};
        for(const auto& word : words2){
            int thisWordArr[26] = {0};
            for(const char& c : word){
                thisWordArr[c-'a']++;
            }
            for(int i = 0; i < 26; ++i){
                word2arr[i] = max(word2arr[i], thisWordArr[i]);
            }
        }
        vector<string> answer;
        for(const auto& word : words1){
            int thisWordArr[26] = {0};
            for(const char& c : word){
                thisWordArr[c-'a']++;
            }
            int isUniversal = true;
            for(int i = 0; i < 26; ++i){
                if(thisWordArr[i] < word2arr[i]){
                    isUniversal = false;
                    break;
                }
            }
            if(isUniversal){
                answer.push_back(word);
            }
        }
        return answer;
    }
};

int main(){
    Solution solution;
    vector<string> input1 = {"amazon","apple","facebook","google","leetcode"};
    vector<string> input2 = {"e","o"};
    vector<string> answer = solution.wordSubsets(input1, input2);
    cout << "Answer: " << endl;
    printVector(answer);
}