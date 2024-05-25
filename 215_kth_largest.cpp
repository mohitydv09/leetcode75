#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        // Add the nums to pq.
        for(int item : nums){
            pq.push(item);
        }
        for (int i = 0; i < k - 1; i++){
            pq.pop();
        }
        return pq.top();
    }
};

int main(){
    Solution solution_instance;
    vector<int> input = {3,2,1,5,6,4};
    int k = 2;
    cout << "Answer : " << solution_instance.findKthLargest(input,k) << endl;
    return 0;
}