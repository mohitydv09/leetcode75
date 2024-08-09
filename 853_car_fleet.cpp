#include<iostream>
#include<vector>
#include<stack>

class Solution {
public:
    int carFleet(int target, std::vector<int>& position, std::vector<int>& speed) {
        std::vector<std::pair<int,int>> combinedVector;
        for (int i = 0; i < position.size(); ++i){
            combinedVector.push_back(std::pair(position[i],speed[i]));
        }
        std::sort(combinedVector.begin(), combinedVector.end());
        std::vector<float> time;
        for (auto& pair : combinedVector){
            time.push_back(static_cast<float>(target-pair.first)/pair.second);
        }
        std::stack<float> stk;
        for (int i = time.size() -1; i >= 0; --i){
            if(stk.size() == 0 || stk.top() < time[i]){
                stk.push(time[i]);
            }
        }
        for(float item : time){
            std::cout << item << std::endl;
        }
        return stk.size();
    }
};

int main(){
    Solution solution;
    std::vector<int> position = {6,8};
    std::vector<int> speed = {3,2};
    int target = 10;
    int answer = solution.carFleet(target, position, speed);
    return 0;
}