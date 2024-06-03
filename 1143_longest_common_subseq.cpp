#include<iostream>

using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int rows = text2.size() + 1;
        int cols = text1.size() + 1;
        vector<vector<int>> grid(rows, vector<int>(cols, 0));

        for(int i = 1; i < rows; i++){
            for(int j = 1; j < cols; j++){
                if(text1[j-1] == text2[i-1]){
                    grid[i][j] = grid[i-1][j-1] + 1;
                }else{
                    grid[i][j] = max(grid[i][j-1], grid[i-1][j]);
                }
            }
        }
        return grid[rows-1][cols-1];
    }
};

int main(){
    Solution solution_instance;
    string text1 = "adcfe";
    string text2 = "ace";
    cout << solution_instance.longestCommonSubsequence(text1, text2) << endl;
}