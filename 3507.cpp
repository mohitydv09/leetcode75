#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int count = 0;
        while(nums.size() > 1){
            bool sorted = true;
            int minSumIndex = 0;
            int minSum = 1000000;
            for(int i = 0; i < nums.size()-1; ++i){
                if(nums[i] > nums[i+1]){
                    sorted = false;
                }
                if(nums[i] + nums[i+1] < minSum){
                    minSum = nums[i] + nums[i+1];
                    minSumIndex = i;
                }
            }
            vector<int> nums2 = {};
            if (!sorted){
                for(int i = 0; i < nums.size(); ++i){
                    if (i == minSumIndex){
                        nums2.push_back(nums[i]+nums[i+1]);
                        i++;
                    }else{
                        nums2.push_back(nums[i]);
                    };
                }
                count++;
            }else{
                return count;
            }
            nums = nums2;
        }
        return count;
    }
};

int main(){
    Solution solution;
    vector<int> input = {2,2,-1,3,-2,2,1,1,1,0,-1};
    int answer = solution.minimumPairRemoval(input);
    cout << "Answer: " << answer << endl;
}