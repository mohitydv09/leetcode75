#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int low = nums[0];
        int high = nums[0];
        for (int i = 1; i < nums.size(); i++){
            if (low == high){
                // No peak has been found yet.
                if (nums[i] > high){
                    // Set a new high.
                    high = nums[i];
                }else {
                    // Both high and low go down.
                    high = nums[i];
                    low = nums[i];
                    }
            }else{
                // One Peak has been found.
                if (nums[i] > high){
                    // Num is greater than earlier peak. Therefore we have found the solution.
                    return true;
                }else if (nums[i] > low){
                    // This peak is lower than last, therefore consider this as the imp peak.
                    high = nums[i];
                }else{
                    // This is a new low value, update the low value.
                    low = nums[i];
                }
                }
            }
        return false;
    }
};

int main(){
    Solution solution_instance;
    vector<int> nums = {2,1,5,0,4,6};
    cout << solution_instance.increasingTriplet(nums) << endl;
    return 0;
}