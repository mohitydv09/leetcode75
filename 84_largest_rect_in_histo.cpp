#include<iostream>
#include<vector>
#include<stack>

class Solution {
public:
    int largestRectangleArea(std::vector<int>& heights) {
        // Stack stores Index and Value
        std::stack<std::pair<int, int>> stk;
        int maxArea = 0;
        for (int i = 0; i < heights.size(); ++i){
            int temp = i;
            while(stk.size() > 0 && stk.top().second > heights[i]){
                temp = stk.top().first;
                int currArea = stk.top().second*(i - stk.top().first);
                maxArea = (currArea > maxArea) ? currArea : maxArea;
                stk.pop();
            }
            stk.push({temp, heights[i]});
        }
        while(stk.size() > 0){
            int currArea = stk.top().second*(heights.size() - stk.top().first);
            maxArea = (currArea > maxArea) ? currArea : maxArea;
            stk.pop();
        }
        return maxArea;
    }
};

int main(){
    Solution solution;
    std::vector<int> heights = {2,1,2};
    int ans = solution.largestRectangleArea(heights);
}