#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {

        // Find the sum of first k nums.
        double first_sum = 0;
        for (int i = 0; i < k; i++){
            first_sum += nums[i];
        }
        
        double max_average = first_sum/k;
        double curr_avg = first_sum/k;
        // iterate over the full list.
        for (int i = 0; i < nums.size() - k ; i++){
            first_sum = first_sum - nums[i];
            first_sum += nums[i+k];

            curr_avg = first_sum/k;
            if (curr_avg > max_average){
                max_average = curr_avg;
            }
        }
        return max_average;
    }
};

int main(){
    Solution solution_instance;
    vector<int> nums = {0,4,0,3,2};
    // vector<int> nums = {-1,-1,-2,-2};
    int k = 1;
    cout << solution_instance.findMaxAverage(nums, k) << endl;
    return 0;
} 