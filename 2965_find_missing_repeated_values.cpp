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
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int> answer = {};
        vector<int> count(grid.size()*grid.size(), 0);
        for(int i = 0; i < grid.size(); ++i){
            for(int j = 0; j < grid.size(); ++j){
                if(count[grid[i][j]-1] == 1){
                    answer.push_back(grid[i][j]);
                }else{
                    count[grid[i][j]-1]++;
                }
            }
        }
        for(int i = 0; i < count.size(); ++i){
            if(count[i] == 0){
                answer.push_back(i+1);
            }
        }
        return answer;
    }
};

int main(){
    Solution solution;
    vector<vector<int>> input = {{1,3}, {2,2}};
    vector<int> answer = solution.findMissingAndRepeatedValues(input);
    cout << "Answer: " << endl;
    printVector(answer);
}