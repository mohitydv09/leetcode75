#include<iostream>
#include<vector>
#include<string>
#include<unordered_set>
#include<unordered_map>
#include<map>
#include<set>
#include<string>
#include<climits>
#include<algorithm>

#include "utils.h"

using namespace std;

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9 + 7;

        vector<vector<pair<int,int>>> adjList(n);
        for(auto& road: roads){
            adjList[road[0]].push_back({road[1], road[2]});
            adjList[road[1]].push_back({road[0], road[2]});
        }

        // Dijkstra: keep time, node
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> frontier;

        vector<long long> shortestTime(n, LLONG_MAX);

        vector<int> pathCount(n, 0);

        shortestTime[0] = 0;
        pathCount[0] = 1;

        frontier.emplace(0, 0);

        while(!frontier.empty()){
            long long currTime = frontier.top().first;
            int currNode = frontier.top().second;
            frontier.pop();

            if(currTime > shortestTime[currNode]) continue;

            for(auto& [neighNode, pathTime] : adjList[currNode]){
                if(currTime + pathTime < shortestTime[neighNode]){
                    shortestTime[neighNode] = currTime + pathTime;
                    pathCount[neighNode] = pathCount[currNode];
                    frontier.emplace(shortestTime[neighNode], neighNode);
                }else if(currTime + pathTime == shortestTime[neighNode]){
                    pathCount[neighNode] = (pathCount[neighNode] + pathCount[currNode]) % MOD;
                }
            }
        }
        return pathCount[n-1];
    }
};

int main(){
    Solution solution;
    vector<vector<int>> roads = {{0,6,7},{0,1,2},{1,2,3},{1,3,3},{6,3,3},{3,5,1},{6,5,1},{2,5,1},{0,4,5},{4,6,2}};
    int answer = solution.countPaths(7, roads);
    cout << "Answer: " << answer << endl;
}