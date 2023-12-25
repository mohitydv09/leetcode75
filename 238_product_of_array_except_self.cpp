#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        //  Make the forward pass vector.
        vector<int> forward_pass(nums.size(),1);
        int prod = 1;
        for (int i = 1 ; i < nums.size() ; i++){
            // cout << nums[i] << endl;
            prod = prod*nums[i-1];
            forward_pass[i]=prod;
        }

        // Make the backword pass vector.
        vector<int> backward_pass(nums.size(),1);
        prod = 1;
        for (int i = nums.size()-2; i >= 0 ; i--){
            prod = prod*nums[i+1];
            backward_pass[i]=prod;
        }

        // Make the product vector.
        vector<int> answer(nums.size());
        for (int i = 0; i < nums.size(); i++){
            answer[i] = forward_pass[i] * backward_pass[i];
        }

        // Print Answer.
        for (int item : answer){
            cout << item << endl;
        }
        return answer;
    }
};

int main(){
    Solution solution_instance;
    vector<int> nums = {-1,1,0,-3,3};
    vector<int> answer = solution_instance.productExceptSelf(nums);
    // cout << solution_instance.productExceptSelf(nums) << endl;
    return 0;
}