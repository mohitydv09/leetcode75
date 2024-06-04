#include<iostream>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        if(word1.size() == 0 && word2.size() == 0){
            return 0;
        }else if (word1.size()==0){
            return word2.size();
        }else if (word2.size()==0){
            return word1.size();
        }
        vector<vector<int>> grid(word1.size()+1,vector<int>(word2.size()+1,0));
        for(int i = 0; i < grid.size(); i++){
            grid[i][0] = i;
        }
        for (int j = 0; j < grid[0].size(); j++){
            grid[0][j] = j;
        }
        for(int i = 1; i < grid.size(); i++){
            for(int j = 1; j < grid[0].size(); j++){
                if(word1[i-1] != word2[j-1]){
                    grid[i][j] = 1 + min({grid[i-1][j], grid[i][j-1], grid[i-1][j-1]});
                }else{
                    grid[i][j] = grid[i-1][j-1];
                }
            }

        }
        cout << "Grid : " << endl;
        for (vector<int> row : grid){
            for(int item : row){
                cout << item << " ";
            }
            cout << endl;
        }
        return grid[grid.size()-1][grid[0].size()-1];
    }
};

int main(){
    Solution solution_instance;
    // string word1 = "horse";
    string word1 = "zoologicoarchaeologist";
    // string word2 = "ros"; 
    string word2 = "zoogeologist";

    cout << "Ans : " << solution_instance.minDistance(word1, word2) << endl;
}