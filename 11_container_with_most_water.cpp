#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_water = 0;
        int iter_front = 0;
        int iter_back = height.size()-1;
        // Run while both the pointers are different.
        while(iter_front != iter_back){
            int capacity = (iter_back - iter_front) * min(height[iter_front],height[iter_back]);
            if(capacity > max_water){
                max_water = capacity;
            }
            // Change teh pointers according to size.
            if(height[iter_front] > height[iter_back]){
                iter_back--;
            }else{
                iter_front++;
            }
        }
        return max_water;
    }
};

int main(){
    Solution solution_instance;
    vector<int> nums = {1,8,6,2,5,4,8,3,7};
    cout << solution_instance.maxArea(nums) << endl;
    return 0;
} 