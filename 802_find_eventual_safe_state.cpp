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
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool> visited(n, false), currPath(n, false);

        for(int i = 0; i < n; ++i){
            dfs(i, graph, visited, currPath);
        }
        // CurrPath now has all the cycle elements.
        vector<int> answer;
        for(int i = 0; i < n; ++i){
            if(!currPath[i]){
                answer.push_back(i);
            }
        }
        return answer;
    }
private:
    bool dfs(int node, vector<vector<int>>& graph, vector<bool>& visited, vector<bool>& currPath){
        if(currPath[node]){
            return true;
        }
        if(visited[node]){
            return false;
        }
        visited[node] = true;
        currPath[node] = true;
        for(int& neigh : graph[node]){
            if(dfs(neigh, graph, visited, currPath)){
                return true;
            };
        }
        currPath[node] = false;
        return false;
    }
};

int main(){
    Solution solution;
    vector<vector<int>> input = {{1,2},{2,3},{5},{0},{5},{},{}};
    vector<int> answer = solution.eventualSafeNodes(input);
    cout << "Answer: " << endl;
    printVector(answer);
}