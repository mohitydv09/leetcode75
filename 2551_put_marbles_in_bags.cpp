#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<map>
#include<set>
#include<string>
#include<algorithm>
#include<numeric>

#include "utils.h"

using namespace std;

class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        if(weights.size() == 1){return 0;}
        vector<long long> sumOfPairs;
        for(int i = 0; i < weights.size()-1; ++i){
            sumOfPairs.push_back(weights[i] + weights[i+1]);
        }
        sort(sumOfPairs.begin(), sumOfPairs.end());
        long long sumMin = 0;
        long long sumMax = 0;
        for(int i = 0; i < k-1; ++i){
            sumMin += sumOfPairs[i];
            sumMax += sumOfPairs[sumOfPairs.size()-1-i];
        }
        return sumMax - sumMin;
    }
};

int main(){
    Solution solution;
    vector<int> weights = {11};
    long long answer = solution.putMarbles(weights, 2);
    cout << "Answer: " << answer << endl;
}