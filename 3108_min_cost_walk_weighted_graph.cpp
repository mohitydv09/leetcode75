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
    vector<int> parent;
    vector<int> depth;

    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        parent.resize(n, -1); // Let the parent be same size as n.
        depth.resize(n, 0);

        // Construct the Disjoint Set
        for(auto& edge : edges){
            Union(edge[0], edge[1]);
        }

        // -1 will be very high value.
        vector<unsigned int> componentCost(n, -1);
        // Calculate Component Cost.
        for(auto& edge : edges){
            int root = find(edge[0]);
            componentCost[root] &= edge[2];
        }

        vector<int> answer;
        for(auto& q : query){
            int root_x = find(q[0]);
            int root_y = find(q[1]);

            answer.push_back((root_x == root_y) ? componentCost[root_x] : -1);
        }

        return answer;
    }

private:
    int find(int node){
        while(parent[node] != -1){
            node = parent[node];
        }
        return node;
    }

    void Union(int x, int y){
        int root_x = find(x);
        int root_y = find(y);

        if(root_x == root_y) return;

        // More depth item should be parent.
        if(depth[root_y] > depth[root_x]) swap(root_x, root_y);

        parent[root_y] = root_x;

        if(depth[root_x] == depth[root_y]) depth[root_x]++;
    }
};

int main(){
    Solution solution;
    vector<vector<int>> edges = {{0,1,7}, {1,3,7}, {1,2,1}};
    vector<vector<int>> query = {{0,3}, {3,4}};
    vector<int> answer = solution.minimumCost(5, edges, query);
    cout << "Answer: " << endl;
    printVector(answer);
}