#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<int> one_minus_two;
        vector<int> two_minus_one;

        //  Sort the two recieved arrays.
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        // Remove duplicated from the two arrays.
        vector<int> nums1_set = {nums1[0]};
        vector<int> nums2_set = {nums2[0]};
        for(int i = 1; i < nums1.size(); i++){
            if (nums1[i] != nums1[i-1]){
                nums1_set.push_back(nums1[i]);
            }
        }
        for(int i = 1; i < nums2.size(); i++){
            if (nums2[i] != nums2[i-1]){
                nums2_set.push_back(nums2[i]);
            }
        }

        // Remove items from 1 that are not in 2.
        int i = 0;
        int j = 0;
        while (i < nums1_set.size()){
            if(nums1_set[i] < nums2_set[j]){
                one_minus_two.push_back(nums1_set[i]);
                i++;
            }else if(nums1_set[i] > nums2_set[j]){
                j++;
                if(j >= nums2_set.size()){
                    one_minus_two.push_back(nums1_set[i]);
                    j--;
                    i++;
                }
            }else{
                i++;
            }
        }

        // Remove items from 1 that are not in 2.
        int i2 = 0;
        int j2 = 0;
        while (i2 < nums2_set.size()){
            if(nums2_set[i2] < nums1_set[j2]){
                two_minus_one.push_back(nums2_set[i2]);
                i2++;
            }else if(nums2_set[i2] > nums1_set[j2]){
                j2++;
                if(j2 >= nums1_set.size()){
                    two_minus_one.push_back(nums2_set[i2]);
                    j2--;
                    i2++;
                }
            }else{
                i2++;
            }
        }

        for (int item : two_minus_one){
            cout << item << " ";
        }
        cout << endl;
        return 0;
     }
};

int main(){
    Solution solution_instance;
    vector<int> nums1 = {1,2,3};
    vector<int> nums2 = {2,4,6};
    solution_instance.findDifference(nums1, nums2);
    return 0;
} 