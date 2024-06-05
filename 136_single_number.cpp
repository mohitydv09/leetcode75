#include<iostream>

using namespace std;

// See properties of XOR funtion.

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++){
            ans ^= nums[i];
        }
        return ans;
    }
};

int main(){
    Solution solution_instance;
    vector<int> nums = {4,1,2,1,2};
    cout << "Ans : " << solution_instance.singleNumber(nums) << endl;
}