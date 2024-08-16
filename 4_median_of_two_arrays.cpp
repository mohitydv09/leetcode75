#include<iostream>
#include<vector>
#include<climits>

class Solution {
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        int posInf = INT_MAX;
        int negInf = INT_MIN;

        int totalElements = nums1.size() + nums2.size();
        int middle = totalElements/2;

        std::vector<int>& small = (nums1.size() < nums2.size()) ? nums1 : nums2;
        std::vector<int>& large = (nums1.size() < nums2.size()) ? nums2 : nums1;

        int left = 0;
        int right = small.size() - 1;
        int mid;
        while(true){
            mid = std::floor((left + right)/2.0);
            std::cout << "Mid: " << mid << std::endl;
            int mid2 = middle - mid - 2;

            int smallLast = (mid >= 0) ? small[mid] : negInf;
            int smallLast1 = (mid + 1 < small.size()) ? small[mid + 1] : posInf;
            int largeLast = (mid2 >= 0) ? large[mid2] : negInf;
            int largeLast1 = (mid2 + 1 < large.size()) ? large[mid2 + 1] : posInf;

            if(smallLast <= largeLast1 && largeLast <= smallLast1){
                // Valid Partition return the value.
                if(totalElements%2 == 0){
                    //Even Value.
                    return static_cast<double>(std::max(smallLast, largeLast) + std::min(smallLast1 ,largeLast1)) / 2;
                }else{
                    //Odd case.
                    return std::min(smallLast1, largeLast1);
                }
            }else if(smallLast > largeLast1){
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }
    }
};

int main(){
    Solution solution;
    std::vector<int> nums1 = {1,2};
    std::vector<int> nums2 = {3,4};
    double ans = solution.findMedianSortedArrays(nums1, nums2);
    std::cout << "Answer: " << ans << std::endl;
}