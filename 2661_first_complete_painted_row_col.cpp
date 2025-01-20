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
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {

        int m = mat.size();
        int n = mat[0].size();
        vector<int> rows(m, n);
        vector<int> cols(n, m);

        unordered_map<int, pair<int, int>> num2pos; // Store num location.

        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                num2pos[mat[i][j]] = {i, j};
            }
        }

        for(int i = 0; i < arr.size(); ++i){
            auto[row, col] = num2pos[arr[i]];
            rows[row]--;
            cols[col]--;
            if(rows[row] == 0 || cols[col] == 0){
                return i;
            }
        }
        return -1;
    }
};

int main(){
    Solution solution;
    vector<int> arr = {1,3,4,2};
    vector<vector<int>> mat = {{1,4}, {2,3}};
    int answer = solution.firstCompleteIndex(arr, mat);
    cout << "Answer: " << answer << endl;
}