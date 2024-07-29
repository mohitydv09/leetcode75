#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int front = 0;
        int back = nums.size()-1;
        vector<vector<int>> answer;
        for (int i = 0; i < nums.size() - 2; ++i){
            if(i > 0 && nums[i] == nums[i-1]){
                continue;
            }
            int target = - nums[i];
            int first = i + 1;
            int second = nums.size() - 1;
            while (first < second){
                if(nums[first] + nums[second] < target){
                    first++;
                }else if(nums[first] + nums[second] > target){
                    second--;
                }else{
                    answer.push_back({nums[i], nums[first], nums[second]});
                    first++;
                    while(nums[first] == nums[first-1] && first < second){
                        first++;
                    }
                }
            }
        }
        return answer;
    }
};

int main(){
    Solution solution;;
    vector<int> input_ = {-4,-1,-1,0,1,2};
    vector<vector<int>> answer = solution.threeSum(input_);
    for(auto item : answer){
        cout << endl;
        for (int item2 : item){
            cout << item2 ;
        }
    }
}