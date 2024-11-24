#include<iostream>
#include<vector>
#include<algorithm>

class Solution {
public:
    int eraseOverlapIntervals(std::vector<std::vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end());

        int ans = 0;
        int currEnd = intervals[0][1]; 
        for (int i = 1; i < intervals.size(); i++){
            if(intervals[i][0] < currEnd){
                ans++;
                currEnd = std::min(currEnd,intervals[i][1]);
            }else{
                currEnd = intervals[i][1];
            }
        }
        return ans;
    }
};

int main(){
    Solution solution;
    std::vector<std::vector<int>> intervals = {{0,2},{1,3},{2,4},{3,5},{4,6}};
    int answer = solution.eraseOverlapIntervals(intervals);
    std::cout << "Answer: " << answer << std::endl;
}