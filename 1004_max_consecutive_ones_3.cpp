#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        // Make two iterators.
        int i = 0;
        int zeros = k;
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
            if( j+1-i > max_count){max_count = j+1-i;}
        }
        return max_count;
    }
};

int main(){
    Solution solution_instance;
    vector<int> nums = {0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1};
    int k = 3;
    cout << solution_instance.longestOnes(nums, k) << endl;
    return 0;
} 