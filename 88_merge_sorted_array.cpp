#include <iostream>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1;
        int j = n-1;
        int k = m+n-1;
        while (i >= 0 && j >= 0){
            if (nums1[i] > nums2[j]){
                nums1[k] = nums1[i];
                i--;
            }else{
                nums1[k] = nums2[j];
                j--;
            }
            k--;
        }
        while(j >= 0){
            nums1[k] = nums2[j];
            j--;
            k--;
        }


        for(int item : nums1){
            std::cout << item << std::endl;
        }
    }
};

int main(){
    Solution solution;
    vector<int> nums1 = {0};
    int m = 0;
    vector<int> nums2 = {1};
    int n = 1;
    solution.merge(nums1, m, nums2, n);
}