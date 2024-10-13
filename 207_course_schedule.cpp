#include<iostream>
#include<vector>

class Solution {
public:
    bool canFinish(int numCourses, std::vector<std::vector<int>>& prerequisites) { 
        std::vector<std::vector<int>> adjList(numCourses, std::vector<int>{});
        for(auto item : prerequisites){
            adjList[item[0]].push_back(item[1]);
        }
        std::vector<bool> visited(numCourses, false);

        for(int i = 0; i < numCourses; ++i){
            bool ans = dfs(i, adjList, visited);
            if (!ans){
                return false;
            }
        }
        return true;
    }
private:
    bool dfs(int course, std::vector<std::vector<int>>& adjList, std::vector<bool>& visited){
        if (visited[course]){
            // Loop detected return false.
            return false;
        }
        if (adjList.size() == 0){
            //As this doesnt need priors this is a pass.
            return true;
        }
        visited[course] = true;
        for(int preReq : adjList[course]){
            bool ans = dfs(preReq, adjList, visited);
            if(!ans){
                return false;
            }
        }
        adjList[course].clear();
        visited[course] = false;
        return true;
    }
};

int main(){
    Solution solution;
    int numCources = 2;
    std::vector<std::vector<int>> prerequisites = {{1,0},{0,1}};
    std::cout << "Answer: " << solution.canFinish(numCources, prerequisites) << std::endl;
}