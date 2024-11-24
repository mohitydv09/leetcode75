#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<algorithm>

class Solution {
public:
    std::vector<int> minInterval(std::vector<std::vector<int>>& intervals, std::vector<int>& queries) {
        std::sort(intervals.begin(), intervals.end());
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int,int>>, std::greater<std::pair<int,int>>> minHeap; // Store the Size and Right of the inteval.

        std::vector<int> sortedQueries = queries;
        std::sort(sortedQueries.begin(), sortedQueries.end());
        int i = 0;
        std::unordered_map<int, int> result;
        for(int query: sortedQueries){
            while(i < intervals.size() && intervals[i][0] <= query){
                minHeap.push({intervals[i][1] - intervals[i][0] + 1, intervals[i][1]});
                i++;
            }
            while(!minHeap.empty() && minHeap.top().second < query){
                minHeap.pop();
            }
            result[query] = (minHeap.empty()) ? -1 : minHeap.top().first;
        }
        std::vector<int> answer;
        for (int q : queries){
            answer.push_back(result[q]);
        }
        return answer;
    }
};

int main(){
    Solution solution;
    std::vector<std::vector<int>> intervals = {{2,3},{2,5},{1,8},{20,25}};
    std::vector<int> queries = {2,19,5,22};
    std::vector<int> answer = solution.minInterval(intervals, queries);
    std::cout << "Answer: ";
    for (int item: answer){
        std::cout << item << " ";
    }
    std::cout << std::endl;
}