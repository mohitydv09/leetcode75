#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<map>
#include<set>
#include<string>
#include<algorithm>

#include "utils.h"

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        for(int& num : nums){
            pq.emplace(num);
        }
        int numOperations = 0;
        while(pq.top() < k){
            long long one = pq.top(); pq.pop();
            long long two = pq.top(); pq.pop();
            pq.emplace(2*one + two);
            numOperations++;
        }
        return numOperations;
    }
};

int main(){
    Solution solution;
    vector<int> input = {2,11,10,1,3};
    int answer = solution.minOperations(input, 10);
    cout << "Answer: " << answer << endl;
}