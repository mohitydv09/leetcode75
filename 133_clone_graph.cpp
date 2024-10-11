#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>

class Node {
public:
    int val;
    std::vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = std::vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = std::vector<Node*>();
    }
    Node(int _val, std::vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node){return nullptr;}
        std::unordered_map<int, Node*> hashMap;
    
        Node* rootNode = new Node(node->val);
        hashMap[rootNode->val] = rootNode;

        std::queue<Node*> frontier;
        frontier.push(node);

        while(!frontier.empty()){
            Node* currNode = frontier.front(); frontier.pop();

            for(auto neighbour : currNode->neighbors){
                if(!hashMap[neighbour->val]){
                    Node* new_neigh = new Node(neighbour->val);
                    hashMap[new_neigh->val] = new_neigh;
                    frontier.push(neighbour);
                }
                hashMap[currNode->val]->neighbors.push_back(hashMap[neighbour->val]);
            }
        }
        return rootNode;
    }
};

int main(){
    Solution solution;
    std::vector<std::vector<int>> adj_mat = {{2,4},{1,3},{2,4},{1,3}};

    // Create Nodes from the adjacency matrix.
    std::vector<Node*> nodes;
    for (int i = 0; i < adj_mat.size(); ++i){
        Node* new_node = new Node(i+1);
        nodes.push_back(new_node);
    }
    for (int i = 0; i < adj_mat.size(); ++i){
        for(int j = 0; j < adj_mat[i].size(); ++j){
            nodes[i]->neighbors.push_back(nodes[adj_mat[i][j]-1]);
        }
    }

    Node* answer = solution.cloneGraph(nodes[0]);
    
}