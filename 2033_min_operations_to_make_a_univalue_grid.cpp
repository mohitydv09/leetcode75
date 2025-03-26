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
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> flatGrid;
        int remainder = grid[0][0]%x;
        for(int i = 0; i < grid.size(); ++i){
            for(int j = 0; j < grid[0].size(); ++j){
                if(grid[i][j]%x != remainder){
                    return -1;
                }
                flatGrid.push_back(grid[i][j]);
            }
        }
        sort(flatGrid.begin(), flatGrid.end());
        int median = flatGrid[flatGrid.size()/2];
        int answer = 0;
        for(int i = 0; i < flatGrid.size(); ++i){
            answer += abs(median - flatGrid[i])/x;
        }
        return answer;
    }
};

int main(){
    Solution solution;
    vector<vector<int>> input = {{2,4}, {6,8}};
    int answer = solution.minOperations(input, 2);
    cout << "Answer: " << answer << endl;
}