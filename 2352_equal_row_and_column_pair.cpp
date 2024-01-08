#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        // Brute force will be n^3. But n is less than 200 so we can try brute force.
        int n = grid.size();
        int count = 0;

        // Make the vector to store the columns.
        vector<vector<int>> grid_transpose;
        for (int i = 0; i < n; i++ ){
            vector<int> temp;
            for(int j = 0; j < n; j++){
                temp.push_back(grid[j][i]);
            }
            grid_transpose.push_back(temp);
        }
        
        // Do the comparisions.
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if(grid[i] == grid_transpose[j]){
                    count++;
                }
            }
        }

        return count;
    }
};

int main(){
    Solution solution_instance;
    vector<vector<int>> grid;
    grid = {{3,1,2,2},{1,4,4,5},{2,4,2,2},{2,4,2,2}};
    cout << solution_instance.equalPairs(grid);
    return 0;
} 