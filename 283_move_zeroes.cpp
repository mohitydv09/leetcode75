#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    void moveZeroes(vector<int>& nums){
        int iter = 0;
        for (int i = 0; i < nums.size(); i++ ){
            if (nums[iter] == 0){
                nums.erase(nums.begin() + iter);
                nums.push_back(0);
            }else{
                iter++;
            }
        }
        // Print nums
        // for(int item : nums){
        //     cout << item << " ";
        // }
    }
};

int main(){
    Solution solution_instance;
    vector<int> nums = {0,2,3,5,8,0,10};
    solution_instance.moveZeroes(nums);
    // cout << solution_instance.moveZeroes(nums) << endl;
    return 0;
}