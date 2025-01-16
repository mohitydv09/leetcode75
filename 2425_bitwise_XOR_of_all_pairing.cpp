#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<map>
#include<set>
#include<string>
#include<algorithm>

#include "utils.h"

using namespace std;

class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int answer = 0;
        if(nums1.size() % 2 == 1){
            for(int i = 0; i < nums2.size(); ++i){
                answer ^= nums2[i];
            }
        }
        if(nums2.size() % 2 == 1){
            for(int i = 0; i < nums1.size(); ++i){
                answer ^= nums1[i];
            }
        }
        return answer;
    }
};

int main(){
    Solution solution;
    vector<int> nums1 = {2,1,3};
    vector<int> nums2 = {10,2,5,0};
    int answer = solution.xorAllNums(nums1, nums2);
    cout << "Answer: " << answer << endl;
}