#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<unordered_set>

/*
Dijkstra's algorithm
*/

class Solution {
public:
    int networkDelayTime(std::vector<std::vector<int>>& times, int n, int k) {
        // Form the adjacency list.
        std::unordered_map<int, std::vector<std::pair<int, int>>> adjList; // HashMap to map a node to its neighs: NODE, DIST
        for (auto edge: times){
            adjList[edge[0]].push_back({edge[1], edge[2]});
        }

        std::unordered_set<int> visited;
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> frontier; // Stores, Min Dist to reach this node via this path, NODE.
        frontier.push({0,k});

        int minDist = 0;
        while(!frontier.empty()){
            auto[dist, node] = frontier.top(); frontier.pop();
            if(visited.find(node) != visited.end()){continue;} // Continue if the node was already visited.
            minDist = std::max(minDist, dist);
            visited.insert(node);
            for(auto neigh : adjList[node]){
                auto[neighNode, edgeDist] = neigh;
                if(visited.find(neighNode) == visited.end()){
                    frontier.push({dist+edgeDist, neighNode});
                }
            }
        }
        return (visited.size() == n) ? minDist : -1;
    }
};

int main(){
    Solution solution;
    std::vector<std::vector<int>> times = {{2,1,1},{2,3,1},{3,4,1}};
    std::cout << "Answer: " << solution.networkDelayTime(times, 4, 2) << std::endl;
}