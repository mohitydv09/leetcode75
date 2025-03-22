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
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjList(n);
        for(auto& edge : edges){
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }

        int answer = 0;
        vector<bool> visited(n, false);
        for(int node = 0; node < n; ++node){
            if(!visited[node]){
                answer += isComplete(node, adjList, visited);
            }
        }
        return answer;
    }   

private:
    bool isComplete(int node, vector<vector<int>>& adjList, vector<bool>& visited){
        int num_nodes = 0;
        int num_edges = 0;

        queue<int> frontier;
        frontier.push(node);

        while(!frontier.empty()){
            int curr_node = frontier.front();
            if(!visited[curr_node]){
                visited[curr_node] = true;
                num_nodes++;
                for(int& neigh : adjList[curr_node]){
                    if(!visited[neigh]){
                        num_edges++;
                        frontier.push(neigh);
                    }
                }
            }
            frontier.pop();
        }
        return num_edges == (num_nodes * (num_nodes - 1)) / 2;
    }
};

int main(){
    Solution solution;
    vector<vector<int>> edges = {{0,1}, {0,2}, {1,2}, {3,4}, {3,5}};
    int answer = solution.countCompleteComponents(6, edges);
    cout << "Answer: " << answer << endl;
}