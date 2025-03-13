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
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), sum = 0, k = 0;
        vector<int> diffArray(n+1); //n+1 as the diff array right works on the next idx.

        for(int idx = 0; idx < n; ++idx){
            while(sum + diffArray[idx] < nums[idx]){
                k++;
                if( k > queries.size()){
                    return -1;
                }
                int left = queries[k - 1][0], right = queries[k - 1][1], val = queries[k - 1][2];
                if (right >= idx){// if this is not satisfied that it is a useless query.
                    diffArray[max(left, idx)] += val;
                    diffArray[right + 1] -= val;
                }
            }
            sum += diffArray[idx]; // Collect the max amount that can be subtracted for the given idx.
        }
        return k;
    }
};

int main(){
    Solution solution;
    vector<int> nums = {2,0,2};
    vector<vector<int>> queries = {{0,2,1}, {0,2,1}, {1,1,3}};
    int answer = solution.minZeroArray(nums, queries);
    cout << "Answer: " << answer << endl;
}