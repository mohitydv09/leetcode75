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
vector<vector<int>> allPaths;
public:
    vector<int> longestSpecialPath(vector<vector<int>>& edges, vector<int>& nums) {
        vector<vector<int>> adjList(edges.size()+1);
        for(const vector<int>& edge : edges){
            adjList[edge[0]] = {edge[1], edge[2]};
        }
        vector<vector<int>> currPath = {}; // will store edges
        formPath(0, currPath, edges, adjList, nums);
        
    }

private:
    void formPath(int root, vector<int>& currPath, vector<vector<int>>& edges, vector<vector<int>>& adjList, vector<int>& nums){

        currPath.push_back({root, });
        for(int i = 0; i < adjList[root].size(); ++i){
            formPath(adjList[root][i]);
        }
    }
};

int main(){
    Solution solution;
    vector<vector<int>> input = {{0,1,2},{1,2,3},{1,3,5},{1,4,4}};
    vector<int> nums = {2,1,2,1,3,1};
    vector<int> answer = solution.longestSpecialPath(input, nums);
    cout << "Answer: " << endl;
    printVector(answer);
}