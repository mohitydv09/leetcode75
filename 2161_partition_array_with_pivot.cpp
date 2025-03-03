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
        vector<int> pivotArray(vector<int>& nums, int pivot) {
            vector<int> small;
            vector<int> same;
            vector<int> larger;
            for(int i = 0; i < nums.size(); ++i){
                if(nums[i] < pivot){
                    small.push_back(nums[i]);
                }else if(nums[i] > pivot){
                    larger.push_back(nums[i]);
                }else{
                    same.push_back(nums[i]);
                }
            }
            vector<int> answer;
            for(int i = 0; i < small.size(); ++i){
                answer.push_back(small[i]);
            }
            for(int i = 0; i < same.size(); ++i){
                answer.push_back(same[i]);
            }
            for(int i = 0; i < larger.size(); ++i){
                answer.push_back(larger[i]);
            }
            return answer;
        }
    };

int main(){
    Solution solution;
    vector<int> input = {9,12,5,10,14,3,10};
    vector<int> answer = solution.pivotArray(input, 10);
    cout << "Answer: " << endl;
    printVector(answer);
}