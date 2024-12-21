#include<iostream>
#include<vector>

class Solution {
int ans = 0;
public:
    long dfs(int m, int k, std::vector<std::vector<int>>& adjList, std::vector<bool>& visited, std::vector<int>& values){
        visited[m] = true;
        long sum = 0;
        for(int n : adjList[m]){
            if(!visited[n]){
                long nSum = dfs(n, k , adjList, visited, values);
                if(nSum % k == 0){
                    ans++;
                }else{
                    sum += nSum;
                }
            }
        }
        sum += values[m];
        return sum;
    }

    int maxKDivisibleComponents(int n, std::vector<std::vector<int>>& edges, std::vector<int>& values, int k) {
        std::vector<std::vector<int>> adjList(n, std::vector<int>());
        for(int i = 0; i < edges.size(); ++i){
            adjList[edges[i][0]].push_back(edges[i][1]);
            adjList[edges[i][1]].push_back(edges[i][0]);
        }
        std::vector<bool> visited(n, false);
        long sum = dfs(0, k, adjList, visited, values);
        if (sum % k == 0){
            ans++;
        }
        return ans;
    }
};

int main(){
    Solution solution;
    int n = 5;
    std::vector<std::vector<int>> edges = {{0,2},{1,2},{1,3},{2,4}};
    std::vector<int> values = {1,8,1,4,4};
    int answer = solution.maxKDivisibleComponents(n, edges, values, 6);
    std::cout << "Answer: " << answer << std::endl;
}