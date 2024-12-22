#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int countPathsWithXorValue(vector<vector<int>>& grid, int k) {
        int rows = grid.size();
        int cols = grid[0].size(); 
        vector<vector<vector<int>>> dp(grid.size(), vector<vector<int>>(grid[0].size(), vector<int>(16, 0)));
        dp[0][0][grid[0][0]] = 1;
        for(int row = 0; row < rows; ++row){
            for(int col = 0; col < cols; ++col){
                if(row == 0 && col == 0){continue;}
                for(int i = 0; i < 16; ++i){
                    if(row == 0){
                        dp[row][col][i] = (dp[row][col-1][i ^ grid[row][col]]) % 1000000007;
                    }else if(col == 0){
                        dp[row][col][i] = (dp[row-1][col][i ^ grid[row][col]]) % 1000000007;
                    }else{
                        dp[row][col][i] = (dp[row-1][col][i ^ grid[row][col]] + dp[row][col-1][i ^ grid[row][col]]) % 1000000007;
                    }
                }
            }
        }
        return dp[rows-1][cols-1][k];
    }
};

int main(){
    Solution solution;
    vector<vector<int>> grid = {{2,1,5},{7,10,0},{12,6,4}};
    int answer = solution.countPathsWithXorValue(grid, 11);
    cout << "Answer: " << answer << endl;
}