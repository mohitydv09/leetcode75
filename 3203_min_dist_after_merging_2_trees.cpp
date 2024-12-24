#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int maxDepth1 = getMaxDepth(edges1);
        int maxDepth2 = getMaxDepth(edges2);
        int jointDepth = maxDepth1/2 + maxDepth1%2 + maxDepth2/2 + maxDepth2%2 + 1;
        return max(jointDepth, max(maxDepth1, maxDepth2));
    }

private:
    int getMaxDepth(const vector<vector<int>>& edges){
        if(edges.empty()){return 0;}
        unordered_map<int, vector<int>> adjList;
        for(const vector<int>& edge : edges){
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }

        int root = findLeafNode(edges, adjList);

        // Perform BFS to get the depth of the tree.
        int depth = -1;
        queue<int> frontier;
        frontier.push(root);
        vector<bool> visited(edges.size() + 1, false);
        while(!frontier.empty()){
            int currSize = frontier.size();
            for(int i = 0; i < currSize; ++i){
                int currNode = frontier.front(); frontier.pop();
                visited[currNode] = true;
                for(const int& node : adjList[currNode]){
                    if (!visited[node]){
                        frontier.push(node);
                    }
                }
            }
            depth++;
        }
        return depth;
    }

    int findLeafNode(const vector<vector<int>>& edges, unordered_map<int, vector<int>>& adjList){
        int root;
        queue<int> frontier;
        frontier.push(0);
        vector<bool> visited(edges.size() + 1, false);
        while(!frontier.empty()){
            int currSize = frontier.size();
            for(int i = 0; i < currSize; ++i){
                int currNode = frontier.front(); frontier.pop();
                visited[currNode] = true;
                for(const int& node : adjList[currNode]){
                    if (!visited[node]){
                        frontier.push(node);
                        root = node;
                    }
                }
            }
        }
        return root;
    }
};

int main(){
    Solution solution;
    vector<vector<int>> edges1 = {{0,1},{2,0},{3,2},{3,6},{8,7},{4,8},{5,4},{3,5},{3,9}};
    vector<vector<int>> edges2 = {{0,1},{0,2},{0,3}};
    int answer = solution.minimumDiameterAfterMerge(edges1, edges2);
    cout << "Answer: " << answer << endl; 
}