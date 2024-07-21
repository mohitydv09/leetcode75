#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> hashmap;
        int i;
        for (i = 0; i < nums.size(); ++i){
            if(hashmap.count(target - nums[i]) > 0){
                break;
            }else{
                hashmap[nums[i]] = i;
            }
        }
        return {i, hashmap[target - nums[i]]};
    }
};

int main() {
    vector<int> nums = {2,7,11,15};
    int target = 9;
    Solution solution;
    vector<int> answer = solution.twoSum(nums, target);
    cout << "Answer: " ;
    for (int item : answer){
        cout << item;
    }
    cout << endl;
}   