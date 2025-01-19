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
    int trapRainWater(vector<vector<int>>& heightMap) {
        int rows = heightMap.size();
        int cols = heightMap[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false)); 

        auto comp = [](const vector<int>& a , const vector<int>& b){
            return a[0] > b[0];
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> frontier(comp);

        for(int row = 0; row < rows; ++row){
            // First Column.
            frontier.push({heightMap[row][0], row, 0});
            visited[row][0] = true;
            frontier.push({heightMap[row][cols-1], row, cols-1});
            visited[row][cols-1] = true;
        }
        for(int col = 0; col < cols; ++col){
            frontier.push({heightMap[0][col], 0, col});
            visited[0][col] = true;
            frontier.push({heightMap[rows-1][col], rows-1, col});
            visited[rows-1][col] = true;
        }

        vector<vector<int>> directions = {{0,1}, {1, 0}, {-1, 0}, {0, -1}};
        int totalWater = 0;

        while(!frontier.empty()){
            auto item = frontier.top(); frontier.pop();
            int currHeight = item[0];
            int currRow = item[1];
            int currCol = item[2];
            cout << "Curr Row: " << currRow << " Col: " << currCol << endl;
            for(auto dir : directions){
                int neighRow = currRow + dir[0];
                int neighCol = currCol + dir[1];
                if(isValid(neighRow, neighCol, visited)){
                    int neighHeight = heightMap[neighRow][neighCol];
                    cout << "Checking Neigh, Row: " << neighRow << " Col: " << neighCol << " Neigh Height: " << neighHeight << " Curr Boundary Ht: " << currHeight << endl;
                    if(neighHeight < currHeight){
                        //Can fill this
                        int water = currHeight - neighHeight;
                        totalWater += water;
                    }
                    frontier.push({max(currHeight, neighHeight), neighRow, neighCol});
                    visited[neighRow][neighCol] = true;
                }
            }
        }
        return totalWater;
    }
private:
    bool isValid(int row, int col, const vector<vector<bool>>& visited){
        return (row >= 0 && row < visited.size() && col >= 0 && col < visited[0].size() && !visited[row][col]);
    }
};

int main(){
    Solution solution;
    vector<vector<int>> input = {{1,4,3,1,3,2}, {3,2,1,3,2,4}, {2,3,3,2,3,1}};
    int answer = solution.trapRainWater(input);
    cout << "Answer: " << answer << endl;
}