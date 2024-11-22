#include<iostream>
#include<vector>

class Solution {
public:
    std::vector<std::vector<int>> insert(std::vector<std::vector<int>>& intervals, std::vector<int>& newInterval) {
        std::vector<std::vector<int>> answer;

        for(int i = 0; i < intervals.size(); ++i){
            if(newInterval[1] < intervals[i][0]){
                answer.push_back(newInterval);
                std::vector<std::vector<int>> remainingElements(intervals.begin() + i, intervals.end());
                answer.insert(answer.end(), remainingElements.begin(), remainingElements.end());
                return answer;
            }else if(newInterval[0] > intervals[i][1]){
                answer.push_back(intervals[i]);
            }else{
                newInterval[0] = std::min(newInterval[0], intervals[i][0]);
                newInterval[1] = std::max(newInterval[1], intervals[i][1]);
            }
        }
        answer.push_back(newInterval);
        return answer;
    }
};

int main(){
    Solution solution;
    std::vector<std::vector<int>> intervals = {{1,2}, {3,5}, {6,7}, {8,10}, {12,16}};
    std::vector<int> newInterval = {4,8};
    std::vector<std::vector<int>> answer = solution.insert(intervals, newInterval);
    std::cout << "Answer: " << std::endl;
    for(auto interval: answer){
        std::cout << interval[0] << " " << interval[1] << std::endl;
    }
}