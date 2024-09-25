#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
#include<unordered_map>

class Solution {
public:
    int leastInterval(std::vector<char>& tasks, int n) {
        std::unordered_map<char,int> hashMap;
        for(char task : tasks){
            hashMap[task]++;
        }
        std::priority_queue<int, std::vector<int>> maxHeap; 
        for(std::pair items : hashMap){
            maxHeap.emplace(items.second);
        }
        std::queue<std::pair<int, int>> q;
        int time = 0;
        while(!maxHeap.empty() || !q.empty()){
            time++;
            int count;
            if(!maxHeap.empty()){
                count = maxHeap.top() - 1; maxHeap.pop();
                if(count > 0){
                    q.push({count, time + n});
                }
            }
            if (!q.empty() && q.front().second == time){
                maxHeap.emplace(q.front().first);
                q.pop();
            }
        }
        return time;
    }
};

int main(){
    std::vector<char> tasks = {'A','A','A', 'B','B','B', 'A'};
    Solution solution;
    std::cout << "Answer: " << solution.leastInterval(tasks, 3) << std::endl;
}