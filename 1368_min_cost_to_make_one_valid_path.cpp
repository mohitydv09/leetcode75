#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<map>
#include<set>
#include<string>
#include<deque>
#include<algorithm>

#include "utils.h"

using namespace std;

class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> minC(m, vector<int>(n, INT_MAX));
        minC[0][0] = 0;

        deque<pair<int,int>> dq;
        dq.push_front({0,0});
        vector<vector<int>> dirs = {{0,1}, {0,-1},{1,0},{-1,0}};
        while(!dq.empty()){
            // Traverse this node, update the cost to the neightbors and add them to the deque.
            auto[row, col] = dq.front(); dq.pop_front();
            
            for(int i = 0; i < 4; ++i){
                int nxtRow = row + dirs[i][0];
                int nxtCol = col + dirs[i][1];
                int cost = (grid[row][col] != (i+1)) ? 1 : 0;

                if(isValid(nxtRow, nxtCol, m, n) && minC[row][col] + cost < minC[nxtRow][nxtCol]){
                    minC[nxtRow][nxtCol] = minC[row][col] + cost;
                    if(cost == 1){
                        dq.push_back({nxtRow, nxtCol});
                    }else{
                        dq.push_front({nxtRow, nxtCol});
                    }
                }
            }
        }
        return minC[m-1][n-1];
    }

public:
    bool isValid(int row, int col, int m, int n){
        return row >= 0 && row < m && col >= 0 && col < n;
    }
};

int main(){
    Solution solution;
    vector<vector<int>> input = {{1,1,3},{3,2,2},{1,1,4}};
    int answer = solution.minCost(input);
    cout << "Answer: " << answer << endl;
}