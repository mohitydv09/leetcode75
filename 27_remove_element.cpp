#include <iostream>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.size() == 0){
            return 0;
        }else if (nums.size() == 1){
            if(nums[0] == val){
                nums = {};
                return 0;
            }else{
                return 1;
            }
        }
        int i = 0;
        int j = nums.size()-1;
        int k = nums.size();
        while (j > i){
            if(nums[j] == val){
                k--;
                j--;
            }else if(nums[i] == val){
                //swap
                nums[i] = nums[j];
                i++;
                j--;
                k--;
            }else{
                i++;
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
    vector<int> nums = {1};
    int val = 1;
    solution.removeElement(nums, val);
}