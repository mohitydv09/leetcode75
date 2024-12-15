#include<iostream>
#include<vector>
#include<queue>

class Solution {
public:
    double maxAverageRatio(std::vector<std::vector<int>>& classes, int extraStudents) {
        auto compare = [](std::pair<int,int> a, std::pair<int,int> b){
            return ((static_cast<double>(a.first) + 1) / (a.second + 1)) - (static_cast<double>(a.first)/a.second) < ((static_cast<double>(b.first) + 1) / (b.second + 1)) - (static_cast<double>(b.first)/b.second);
        };

        std::priority_queue<
            std::pair<int, int>, 
            std::vector<std::pair<int, int>>, 
            decltype(compare)
        > minHeap(compare);
        double avg = 0;
        for(const std::vector<int>& item : classes){
            avg += static_cast<double>(item[0])/item[1];
            minHeap.push({item[0], item[1]});
        }
        for(int i = 0; i < extraStudents; ++i){
            auto item = minHeap.top(); minHeap.pop();
            avg -= static_cast<double>(item.first)/item.second;
            avg += (static_cast<double>(item.first)+1)/(item.second+1);
            minHeap.emplace(item.first+1, item.second+1);
        }
        return avg/classes.size();
    }
};

int main(){
    Solution solution;
    std::vector<std::vector<int>> classes = {{1,2}, {3,5}, {2,2}};
    double answer = solution.maxAverageRatio(classes, 2);
    std::cout << "Answer: " << answer << std::endl;
}