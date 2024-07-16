#include <iostream>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() < 2){
            return nums.size();
        }

        int i = 0;
        int j = i+1;
        int k = nums.size();
        while (j < nums.size()){
            if(nums[i] == nums[j]){
                j++;
                k--;
            }else{
                if(i+1 != j){
                    nums[i+1] = nums[j];
                }
                i++;
                j++;
            }
        }
        for(int item : nums){
            cout << "Nums: " << item << endl;
        }
        cout << "i:" << i << " j: " << j << " k: " << k << endl;
        nums.resize(k);
        return k;
    }
};

int main(){
    Solution solution;
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
    solution.removeDuplicates(nums);
}