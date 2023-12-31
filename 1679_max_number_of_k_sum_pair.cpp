#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        // Sort the vector.
        sort(nums.begin(), nums.end());

        int iter_front = 0;
        int iter_back = nums.size()-1;
        int counter = 0;
        while(iter_front < iter_back){
            // cout << "Front : " << iter_front << " Back : " << iter_back << endl;
            int sum = nums[iter_front] + nums[iter_back];
            if (sum == k){
                counter++;
                iter_front++;
                iter_back--;
            }else if(sum > k){
                iter_back--;
            }else{
                iter_front++;
            }
        }
        return counter;
    }
};

int main(){
    Solution solution_instance;
    vector<int> nums = {1,2,3,4};
    int k = 5;
    cout << solution_instance.maxOperations(nums, k) << endl;
    return 0;
} 