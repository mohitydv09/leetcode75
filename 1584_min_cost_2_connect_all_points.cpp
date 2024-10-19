#include<iostream>
#include<vector>
#include<unordered_set>
#include<queue>

class Solution {
public:
    int minCostConnectPoints(std::vector<std::vector<int>>& points) {
        int totalCost = 0;
        std::unordered_set<int> visited;
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>> , std::greater<>> frontier; // Will store the dist, idx
        frontier.push({0, 0}); //add  the first item.

        while(visited.size() < points.size()){
            auto [cost, idx] = frontier.top(); frontier.pop();
            if(visited.find(idx) == visited.end()){
                totalCost += cost;
            }else{
                continue;
            }
            visited.insert(idx);
            // Add all the neighs to the frontier.
            for(int i = 0; i < points.size(); ++i){
                if(visited.find(i) == visited.end()){ // Means item is not in visited
                    frontier.push({manhattanDistance(points[idx], points[i]), i});
                }
            }
        }
        return totalCost;
    }

private:
    int manhattanDistance(const std::vector<int>& point1, const std::vector<int>& point2){
        return std::abs(point1[0] - point2[0]) + std::abs(point1[1] - point2[1]);
    }
};

int main(){
    Solution solution;
    std::vector<std::vector<int>> points = {{0,0},{2,2},{3,10},{5,2},{7,0}};
    std::cout << "Answer: " << solution.minCostConnectPoints(points) << std::endl;
}