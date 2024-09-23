#include<iostream>
#include<vector>
#include<queue>
#include<cmath>

class Solution {
public:
    std::vector<std::vector<int>> kClosest(std::vector<std::vector<int>>& points, int k) {

        auto distanceComparator = [](const std::vector<int>& first, const std::vector<int>& second){
            int dist1 = first[0]*first[0] + first[1]*first[1];
            int dist2 = second[0]*second[0] + second[1]*second[1];
            return dist1 > dist2;
        };

        std::priority_queue<std::vector<int>, std::vector<std::vector<int>>, decltype(distanceComparator)> pq(distanceComparator);

        // Push items to pq.
        for(const std::vector<int>& point : points){
            pq.push(point);
        }

        std::vector<std::vector<int>> answer;
        for(int i = 0; i < k; ++i){
            answer.push_back(pq.top());
            pq.pop();
        }
        return answer;
    }
};

int main(){
    std::vector<std::vector<int>> points = {{3,3},{5,-1},{-2,4}};
    Solution solution;
    solution.kClosest(points, 2);
}