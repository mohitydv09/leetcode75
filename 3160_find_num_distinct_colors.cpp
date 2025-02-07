#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<map>
#include<set>
#include<string>
#include<algorithm>

#include "utils.h"

using namespace std;

class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> ball2Color; // ball -> color
        unordered_map<int, unordered_set<int>> color2balls;

        vector<int> answer;

        for(auto& query : queries){
            if(ball2Color.find(query[0]) != ball2Color.end()){
                color2balls[ball2Color[query[0]]].erase(query[0]);
                if(color2balls[ball2Color[query[0]]].size() == 0){
                    color2balls.erase(ball2Color[query[0]]);
                }
            }
            ball2Color[query[0]] = query[1];
            color2balls[query[1]].emplace(query[0]);
            answer.push_back(color2balls.size());
        }
        return answer;
    }
};

int main(){
    Solution solution;
    vector<vector<int>> input = {{0,1},{1,4},{1,1},{1,4},{1,1}};
    vector<int> answer = solution.queryResults(4, input);
    cout << "Answer: " << endl;
    printVector(answer);
}