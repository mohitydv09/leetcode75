#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>

class Solution {
public:
    bool isNStraightHand(std::vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize != 0){
            return false;
        }
        std::unordered_map<int, int> counter;
        std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
        for (int i = 0; i < hand.size(); ++i){
            if(counter[hand[i]] == 0){
                pq.emplace(hand[i]);
            }
            counter[hand[i]]++;
        }
        while(!pq.empty()){
            int start = pq.top();
            for(int i = start; i < start + groupSize; ++i){
                if(counter[i] == 0){
                    return false;
                }
                counter[i]--;
                if(counter[i] == 0){
                    if(i != pq.top()){
                        return false;
                    }
                    pq.pop();
                }
            }
        }
        return true;
    }
};

int main(){
    Solution solution;
    std::vector<int> hand = {1,2,3,6,2,3,4,7,8};
    bool answer = solution.isNStraightHand(hand, 3);
    std::cout << "Answer: " << answer << std::endl;
}