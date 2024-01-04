#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int i = 0;
        int zeros = 1;
        int max_count = 0;
        for(int j = 0; j < nums.size(); j++){
            cout << "j : " << j << " i : " << i << endl;
            if(nums[j] == 0){
                if (zeros > 0){
                    zeros--;
                }else{
                    while(nums[i] != 0){ i++;}
                    i++;
                }
            }
            if( j-i > max_count){max_count = j-i;}
        }
        return max_count;
    }
};

int main(){
    Solution solution_instance;
    vector<int> nums = {1,1,0,1};
    cout << solution_instance.longestSubarray(nums) << endl;
    return 0;
} 