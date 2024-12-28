#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        vector<int> sums(nums.size()-k+1, 0);
        int currSum = 0;
        for(int i = 0; i < k; ++i){
            currSum += nums[i];
        }
        sums[0] = currSum;
        for(int left = 1, right = k; right < nums.size(); ++left, ++right){
            currSum -= nums[left-1];
            currSum += nums[right];
            sums[left] = currSum;
        }
        cout << "Sums: ";
        for (const int& item: sums){
            cout << item << " ";
        }
        cout << endl;
        
        int bestOneScore = 0; 
        int bestTwoScore = 0;
        int bestThreeScore = 0;
        vector<int> bestTwo = {0,0};
        vector<int> answer = {0,0,0};
        int m = 0, n = 0, o = 0;
        for (int i = 0; i < nums.size() - 3*k + 1; ++i){
            if(sums[i] > bestOneScore){
                bestOneScore = sums[i];
                m = i;
            }
            if(bestOneScore + sums[i+k] > bestTwoScore){
                bestTwoScore = bestOneScore + sums[i+k];
                bestTwo[0] = m;
                bestTwo[1] = i + k;
            }
            if(bestTwoScore + sums[i + 2*k] > bestThreeScore){
                bestThreeScore = bestTwoScore + sums[i + 2*k];
                o = i + 2*k;
                answer[0] = bestTwo[0];
                answer[1] = bestTwo[1];
                answer[2] = o;
            }
        }
        return answer;
    }
};

int main(){
    Solution solution;
    vector<int> nums = {4,5,10,6,11,17,4,11,1,3};
    vector<int> answer = solution.maxSumOfThreeSubarrays(nums, 1);
    cout << "Answer: ";
    for(const int& item :answer){
        cout << item << ' ';
    }
    cout << endl;
}