#include<iostream>
#include<vector>
#include<numeric>

class Solution {
public:
    std::vector<int> findRedundantConnection(std::vector<std::vector<int>>& edges) {
        int numNodes = edges.size();
        std::vector<int> parent(numNodes+1);
        std::iota(parent.begin(), parent.end(),0);

        std::vector<int> rank(numNodes+1, 1);
        
        for(int edge = 0; edge < numNodes; ++edge){
            if(!getUnion(edges[edge][0],edges[edge][1], parent, rank)){
                return edges[edge];
            }
        }
    }

private:
    int find(int node, std::vector<int>& parent){
        int par = parent[node];
        while (par != parent[par]){
            parent[par] = parent[parent[par]];
            par = parent[par];
        }
        return par;
    }

    bool getUnion(int node1, int node2, std::vector<int>& parent, std::vector<int>& rank){
        int par1 = find(node1, parent);
        int par2 = find(node2, parent);

        if(par1 == par2){
            return false;
        }

        if(rank[par1] > rank[par2]){
            parent[par2] = par1;
            rank[par1] += rank[par2];
        }else{
            parent[par1] = par2;
            rank[par2] += rank[par1];
        }
        return true;
    }
};

int main(){
    Solution solution;
    std::vector<std::vector<int>> edges = {{2,3},{1,2},{3,4},{1,4},{1,5}};
    std::vector<int> answer = solution.findRedundantConnection(edges);
    std::cout << "Answer: " << answer[0] << answer[1] << std::endl;
}