#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> hashMap; // will store values to all the nums which occur that many times.
        for(int i = 0; i < nums.size(); ++i){
            hashMap[nums[i]]++;
        }

        vector<vector<int>> answer_pair(nums.size()+1, vector<int>{});
        for (auto item : hashMap){
            answer_pair[item.second].push_back(item.first);
        }
        vector<int> answer;
        for (int i = answer_pair.size()-1; i > 0; --i){
            for(int num : answer_pair[i]){
                answer.push_back(num);
                if (answer.size()==k){
                    return answer;
                }
            }
        }
        return answer;
    }
};

int main(){
    Solution solution;
    vector<int> nums = {1,1,1,2,2,3};
    int k = 2;
    vector<int> answer = solution.topKFrequent(nums, k);
}
