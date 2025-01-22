#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<map>
#include<deque>
#include<set>
#include<string>
#include<algorithm>

#include "utils.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int rows = isWater.size();
        int cols = isWater[0].size();

        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        deque<pair<int,int>> frontier;

        for(int row = 0; row < rows; ++row){
            for(int col = 0; col < cols; ++col){
                if(isWater[row][col]){
                    frontier.push_back({row, col});
                    isWater[row][col] = 0;
                    visited[row][col] = true;
                }
            }
        }

        vector<vector<int>> dirs = {{0,1},{1,0},{0,-1},{-1,0}};
        while(!frontier.empty()){
            auto[row, col] = frontier.front(); frontier.pop_front();
            for(auto& dir : dirs){
                int neighRow = row + dir[0];
                int neighCol = col + dir[1];
                if(isValid(neighRow, neighCol, rows, cols) && !visited[neighRow][neighCol]){
                    isWater[neighRow][neighCol] = isWater[row][col] + 1;
                    frontier.push_back({neighRow, neighCol});
                    visited[neighRow][neighCol] = true;
                }
            }
        }
        return isWater;
    }
private:
    bool isValid(int row, int col, int rows, int cols){
        return (row >= 0 && row < rows && col >= 0 && col < cols);
    }
};

int main(){
    Solution solution;
    vector<vector<int>> input = {{0,0,1},{1,0,0},{0,0,0}};
    vector<vector<int>> answer = solution.highestPeak(input);
    cout << "Answer: " << endl;
    for(auto ans : answer){
        printVector(ans);
    }
}