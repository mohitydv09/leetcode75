#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int forward_sum[nums.size()];
        int backward_sum[nums.size()];
        int curr_sum_ford = 0;
        int curr_sum_back = 0;
        for (int i = 0; i < nums.size(); i++){
            curr_sum_ford += nums[i];
            curr_sum_back += nums[nums.size()-1-i];
            forward_sum[i] = curr_sum_ford;
            backward_sum[nums.size()-1-i] = curr_sum_back;
        }
        // for (int item : forward_sum){
        //     cout << item << " ";
        // }
        // cout << endl;
        // for (int item : backward_sum){
        //     cout << item << " ";
        // }
        // cout << endl;
        
        for( int i  = 0; i < nums.size(); i++ ){
            if (forward_sum[i] == backward_sum[i]){
                return i;
            }
        }
        return -1;
    }
};

int main(){
    Solution solution_instance;
    vector<int> nums = {1,7,3,6,5,6};
    cout << solution_instance.pivotIndex(nums) << endl;
    return 0;
} 