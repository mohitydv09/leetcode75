#include <iostream>
#include <deque>

class Solution{
public:
    std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) {
        std::vector<int> answer = {};
        std::deque<int> dq;
        int left = 0;
        int right = 0;
        while(right < nums.size()){
            while(dq.size() > 0 && nums[dq.back()] <= nums[right]){
                dq.pop_back();
            }
            while(dq.size() > 0 && dq.front() < left){
                dq.pop_front();
            }
            dq.push_back(right);
            if(right < k - 1){
                right++;
            }else{
                answer.push_back(nums[dq.front()]);
                right++;
                left++;
            }
        }
        for(int item : answer){
            std::cout << "anseer: " << item << std::endl;
        }
        return answer;
    }
};

int main(){
    Solution solution;
    std::vector<int> nums = {1,3,1,2,0,5};
    int k = 3;
    std::vector<int> answer = solution.maxSlidingWindow(nums, k);
}