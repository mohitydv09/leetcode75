#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
#include<set>

class Solution {
public:
    std::vector<std::string> findItinerary(std::vector<std::vector<std::string>>& tickets) {
        //Make a adj list.
        std::unordered_map<std::string, std::multiset<std::string>> adjList;
        for(const auto& ticket : tickets){
            adjList[ticket[0]].insert(ticket[1]);
        }

        std::vector<std::string> answer;
        dfs("A", adjList, answer);
        std::reverse(answer.begin(), answer.end());
        return answer;
    }

private:
    void dfs(const std::string& node, std::unordered_map<std::string, std::multiset<std::string>>& adjList, std::vector<std::string>& answer){
        while(!adjList[node].empty()){
            auto iter = adjList[node].begin();
            std::string nextNode = *iter;

            adjList[node].erase(iter);
            dfs(nextNode, adjList, answer);
        }
        answer.push_back(node);
    }
};

int main(){
    Solution solution;
    std::vector<std::vector<std::string>> tickets = {{"A","C"},{"A","B"},{"C","A"}};
    std::vector<std::string> answer = solution.findItinerary(tickets);
    std::cout << "Iter: ";
    for (auto item : answer){
        std::cout << item << " "; 
    }
    std::cout << std::endl;
}