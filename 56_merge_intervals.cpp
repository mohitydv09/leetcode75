#include<iostream>
#include<vector>
#include<algorithm>

class Solution {
public:
    std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end());
        std::vector<std::vector<int>> answer;
        for(int i = 0; i < intervals.size(); ++i){
            int j = i;
            int maxEnd = intervals[j][1];
            while(j + 1 < intervals.size() && intervals[j+1][0] <= maxEnd){
                j++;
                maxEnd = std::max(maxEnd, intervals[j][1]);
            }
            answer.push_back({intervals[i][0], maxEnd});
            i = j;
        }
        return answer;
    }
};

int main(){
    Solution solution;
    std::vector<std::vector<int>> intervals = {{2,6}, {1,3}, {8,10}, {15,18}};
    std::vector<std::vector<int>> answer = solution.merge(intervals);
    std::cout << "Answer: " << std::endl;
    for (auto interval : answer){
        std::cout << interval[0] << ' ' << interval[1] << std::endl;
    }
}