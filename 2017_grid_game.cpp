#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<map>
#include<set>
#include<string>
#include<algorithm>
#include<numeric>

#include "utils.h"

using namespace std;

class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        vector<vector<long long>> prefSum(2, vector<long long>(n, 0));
        for(int i = 0; i < n; ++i){
            prefSum[1][i] = (i > 0) ? prefSum[1][i-1] + grid[1][i-1] : 0;
        }
        for(int j = n-1; j >=0; --j){
            prefSum[0][j] = (j < n-1) ? prefSum[0][j+1] + grid[0][j+1] : 0;
        }

        long long maxSecond = max(prefSum[0][0], prefSum[1][0]);
        for(int i = 1; i < n; ++i){
            maxSecond = min(max(prefSum[0][i], prefSum[1][i]), maxSecond);
        }
        return maxSecond;
    }
};

int main(){
    Solution solution;
    vector<vector<int>> input = {{2,5,4},{1,5,1}};
    long long answer = solution.gridGame(input);
    cout << "Answer: " << answer << endl;
}