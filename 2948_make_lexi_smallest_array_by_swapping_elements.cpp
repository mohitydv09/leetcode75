#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<map>
#include<set>
#include<string>
#include<algorithm>
#include<list>

#include "utils.h"

using namespace std;

class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        if(nums.size() == 1){
            return nums;
        }
        vector<int> sortedNums(nums);
        sort(sortedNums.begin(), sortedNums.end());

        int currGroup = 0;
        unordered_map<int, int> int2Group;
        int2Group[sortedNums[0]] = currGroup;
        for(int i = 1; i < sortedNums.size(); ++i){
            if(sortedNums[i] > sortedNums[i-1] + limit){
                currGroup++;
            }
            int2Group[sortedNums[i]] = currGroup;
        }

        // Group to list.
        unordered_map<int, list<int>> group2list; // Group to a list(list deque is sorted)
        for(int i = 0; i < sortedNums.size(); ++i){
            group2list[int2Group[sortedNums[i]]].push_back(sortedNums[i]);
        }

        vector<int> answer;
        for(int i = 0; i < nums.size(); ++i){
            int thisEle = group2list[int2Group[nums[i]]].front(); group2list[int2Group[nums[i]]].pop_front(); 
            answer.push_back(thisEle);
        }
        return answer;
    }
};

int main(){
    Solution solution;
    vector<int> input = {1,5,3,9,8};
    vector<int> answer = solution.lexicographicallySmallestArray(input, 2);
    cout << "Answer: " << endl;
    printVector(answer);
}