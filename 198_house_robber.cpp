#include<iostream>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }
        vector<int> max_loot(nums.size(),0);
        max_loot[0] = nums[0];
        max_loot[1] = max(nums[0], nums[1]);
        for (int i = 2; i < nums.size(); i++){
            max_loot[i] = max(max_loot[i-1], max_loot[i-2] + nums[i]);
        }
        cout << "Max loot";
        for(int loot : max_loot){
            cout << loot << " ";
        }
        cout << endl;
        return 0;
    }
};

int main(){
    Solution sol_instance;
    vector<int> nums = {1,2,3,1};
    cout << sol_instance.rob(nums) << endl;
}