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
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> adjList(numCourses);
        for(auto& prereq : prerequisites){
            adjList[prereq[0]].push_back(prereq[1]);
        }
        vector<bool> answer(queries.size(), false);
        for(int i = 0; i < queries.size(); ++i){
            vector<bool> visited(numCourses, false);
            if(dfs(queries[i][0], queries[i][1], adjList, visited)){
                answer[i] = true;
            }
        }
        return answer;
    }

private:
    bool dfs(int curr, int end, vector<vector<int>>& adjList, vector<bool>& visited){
        if(curr == end){
            return true;
        }
        if(visited[curr]){
            return false;
        }
        visited[curr] = true;
        for(auto& next : adjList[curr]){
            if(dfs(next, end, adjList, visited)){
                return true;
            };
        }
        return false;
    }
};

int main(){
    Solution solution;
    vector<vector<int>> prerequisites = {{1,2}, {1,0}, {2,0}};
    vector<vector<int>> queries = {{1,0}, {1,2}};
    vector<bool> answer = solution.checkIfPrerequisite(3, prerequisites, queries);
    cout << "Answer: "  << endl;
    printVector(answer);
}