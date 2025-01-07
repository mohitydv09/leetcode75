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
    vector<string> stringMatching(vector<string>& words) {
        vector<string> answer;
        for(int i = 0; i < words.size(); ++i){
            int temp = answer.size();
            for(int j = 0; j < words.size(); ++j){
                if(i == j){
                    continue;
                }
                if(words[i].size() <= words[j].size()){
                    for(int k = 0; k < words[j].size() - words[i].size() + 1; ++k){
                        if(words[i] == words[j].substr(k, words[i].size())){
                            answer.push_back(words[i]);
                            break;
                        }
                    }
                }
                if(answer.size() > temp){
                    break;
                }
            }
        }
        return answer;
    }
};

int main(){
    Solution solution;
    vector<string> input = {"leetcoder","leetcode","od","hamlet","am"};
    vector<string> answer = solution.stringMatching(input);
    cout << "Answer: " << endl;
    printVector(answer);
}