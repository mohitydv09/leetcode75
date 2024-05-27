#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int,int>>> front;
        priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int,int>>> back;

        // Initialize the pqs with items.
        int front_idx = 0;
        int back_idx = costs.size()-1;
        for(int i = 0; i < candidates; i++){
            cout << "Front Idx : " << front_idx << " Back Idx  : " << back_idx << endl;
            if(front_idx == back_idx){
                front.push({costs[front_idx], front_idx});
                front_idx++;
                break;
            }else if (front_idx + 1 == back_idx){
                front.push({costs[front_idx], front_idx});
                back.push({costs[back_idx], back_idx});
                front_idx++;
                back_idx--;
                break;
            }else{
                front.push({costs[front_idx], front_idx});
                back.push({costs[back_idx], back_idx});
                front_idx++;
                back_idx--;
            }
        }
        
        long long total_cost = 0;
        while(k--){
            if (front.empty()){
                auto back_top = back.top(); back.pop();
                total_cost += back_top.first;
                continue;
            }
            if (back.empty()){
                auto front_top = front.top(); front.pop();
                total_cost += front_top.first;
                continue;
            }
            auto front_top = front.top();
            auto back_top = back.top();
            cout << "Loop Ran, K is : " << k << endl;
            cout << "Front Idx : " << front_idx << endl;
            cout << "Back Idx : " << back_idx << endl;
            cout << "Top in Front : " << front_top.first << " Back Top : " << back_top.first << endl;
            // Remove from front.
            if(front_top.first <= back_top.first){
                total_cost += front_top.first;
                cout << "Total Cost Updated Front: " << total_cost << endl;
                front.pop();
                if(front_idx <= back_idx){
                    front.push({costs[front_idx], front_idx});
                    front_idx++;
                }
            }else{
                total_cost += back_top.first;
                cout << "Total Cost Updated Back: " << total_cost << endl;
                back.pop();
                if(front_idx <= back_idx){
                    back.push({costs[back_idx], back_idx});
                    back_idx--;
                }
            }
        }
        return total_cost;
    }
};

int main(){
    Solution solution_instance;
    // vector<int> costs = {17,12,10,2,7,2,11,20,8};
    // vector<int> costs = {60,66,17,17,35,46,77,7,15,38,35,61,90,34,29,68,35,9,18,82,78,40,8,71,2,59,70,12,88,73,12,55,88,59,71,49,47,46,65,37,24,75,81,54,39,70};
    vector<int> costs = {57,33,26,76,14,67,24,90,72,37,30};
    cout << costs.size() << endl;
    int k = 11;
    int candidates = 2;
    cout << "Answer : " << solution_instance.totalCost(costs, k, candidates) << endl;
    return 0;
}