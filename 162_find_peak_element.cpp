#include <iostream>

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums){
        if (nums.size() == 1){return 0;} 
        else if(nums.size()==2){
            if(nums[0]>nums[1]){
                return 0;
            }else{
                return 1;
            }
        } 

        int low = 0;
        int high = nums.size()-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(mid == low){
                if(nums[low]>nums[high]){
                    return low;
                }else{
                    return high;
                }
            }else if(mid == high){
                if(nums[low] < nums[high]){
                    return high;
                }else{
                    return low;
                }
            }else if(nums[mid-1] < nums[mid] && nums[mid] > nums[mid+1]){
                return mid;
            }else if(nums[mid] > nums[mid-1] && nums[mid] < nums[mid+1]){
                low = mid+1;
            }else if(nums[mid] < nums[mid-1] && nums[mid] > nums[mid+1]){
                high = mid-1;
            }else{
                high = mid-1;
            }
        }
        return (low+high)/2;
    }
};

int main(){
    Solution solution_instance;
    vector<int> nums = {5,4,3,4,5};
    int ans  = solution_instance.findPeakElement(nums);
    cout << "Ans is : " << ans << endl;
}