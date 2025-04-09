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
        set<int> hashSet;
        for(int& num: nums){
            if(num < k){
                return -1;
            }else if(num > k){
                hashSet.emplace(num);
            }
        }
        return hashSet.size();
    }
};

int main(){
    Solution solution;
    vector<int> input = {5,2,5,4,5};
    int answer = solution.minOperations(input, 2);
    cout << "Answer: " << answer << endl;
}