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
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> countRows(grid.size(), 0);
        vector<int> countCols(grid[0].size(), 0);
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] == 1){
                    countRows[i]++;
                    countCols[j]++;
                }
            }
        }
        int answer = 0;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] == 1 && (countRows[i] > 1 || countCols[j] > 1)){
                    answer++;
                }
            }
        }
        return answer;        
    }
};

int main(){
    Solution solution;
    vector<vector<int>> input = {{1,0}, {0,1}};
    int answer = solution.countServers(input);
    cout << "Answer: " << answer << endl;
}