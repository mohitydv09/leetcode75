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
        bool first = true;
        while (j < nums.size()){
            if(nums[i] == nums[j]){
                if (first){
                    if(i+1 != j){
                        nums[i+1] = nums[j];
                    }
                    i++;
                    j++;
                    first = false;
                }else{
                    j++;
                    k--;
                }
            }else{
                if(i+1 != j){
                    nums[i+1] = nums[j];
                }
                i++;
                j++;
                first = true;
            }
        }
        cout << "Nums: " ;
        for(int item : nums){
            cout << item  << " ";
        }
        cout << endl;
        cout << "i:" << i << " j: " << j << " k: " << k << endl;
        nums.resize(k);
        return k;
    }
};

int main(){
    Solution solution;
    vector<int> nums = {0,0,1,1,1,1,2,3,3};
    solution.removeDuplicates(nums);
}