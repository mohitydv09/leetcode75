#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<bool> visited(isConnected.size(), false);
        int groups = 0;

        for(int i = 0; i < isConnected.size(); i++){
            if(visited[i] == false){
                dfs(i, visited, isConnected);
                groups++;
            }
        }
        return groups;
    }

private:
    void dfs(int city, vector<bool>& visited, vector<vector<int>>& isConnected){
        visited[city] = true;
        for (int i = 0; i < isConnected[city].size(); i++){
            if (isConnected[city][i] == 1 && visited[i] == false){
                dfs(i, visited, isConnected);
            }
        }
    }
};

int main(){
    Solution solution_instance;
    vector<vector<int>> input = {{1,0,0},{0,1,0},{0,0,1}};
    cout << "Answer : " << solution_instance.findCircleNum(input) << endl;
    return 0;
}