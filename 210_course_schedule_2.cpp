#include<iostream>
#include<vector>
#include<unordered_set>

class Solution {
public:
    std::vector<int> findOrder(int numCourses, std::vector<std::vector<int>>& prerequisites) {
        std::vector<std::vector<int>> adjList(numCourses, std::vector<int>{});
        for(auto item : prerequisites){
            adjList[item[0]].push_back(item[1]);
        }
        std::vector<bool> visited(numCourses, false);
        std::vector<bool> currNodes(numCourses, false);

        for(int course = 0; course < numCourses; ++course){
            bool ans = topoSort(course, adjList, visited, currNodes);
            if(!ans){
                return {};
            }
        }
        return answer;
    }

private:
    std::vector<int> answer;
    bool topoSort(int course, std::vector<std::vector<int>>& adjList, std::vector<bool>& visited, std::vector<bool>& currNodes){
        // Check for cycle first.
        if(currNodes[course]){
            return false;
        }   
        // Check if already visited.
        if(visited[course]){
            return true;
        }
        
        visited[course] = true;

        currNodes[course] = true;
        for (int preReq : adjList[course]){
            bool ans = topoSort(preReq, adjList, visited, currNodes);
            if(!ans){
                return false;
            }
        }
        answer.push_back(course);
        currNodes[course] = false;
        return true;
    }
};

int main(){
    Solution solution;
    int numCources = 4;
    std::vector<std::vector<int>> prerequisites = {{1,0},{2,0},{3,1},{3,2}};
    std::vector<int> answer = solution.findOrder(numCources, prerequisites);
    std::cout << "Answer: " << std::endl;
    for (int item : answer){
        std::cout << item << " ";
    }
    std::cout << std::endl;
}