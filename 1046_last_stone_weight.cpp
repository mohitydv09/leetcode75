#include<iostream>
#include<vector>
#include<queue>

class Solution {
public:
    int lastStoneWeight(std::vector<int>& stones) {
        std::priority_queue<int> maxHeap;
        for(int i = 0; i < stones.size(); ++i){
            maxHeap.emplace(stones[i]);
        }
        while(maxHeap.size() > 1){
            int top = maxHeap.top(); maxHeap.pop();
            int top2 = maxHeap.top(); maxHeap.pop();
            if(top != top2){
                maxHeap.emplace(top - top2);
            }
        }
        if(maxHeap.empty()){return 0;}
        return maxHeap.top();
    }
};

int main(){
    Solution solution;
    std::vector<int> stones = {2,7,4,1,8,1};
    int answer = solution.lastStoneWeight(stones);
    std::cout << "Answer: " << answer << std::endl;
}