#include<iostream>
#include<vector>
#include<queue>
#include<cmath>

class Solution {
public:
    int findKthLargest(std::vector<int>& nums, int k) {
        std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

        for (int num : nums){
            std::cout << "Num is: " << num << std::endl;
            if(minHeap.size() >= k){
                std::cout << "Heap Size exceded " << std::endl;
                if(num > minHeap.top()){
                    minHeap.pop();
                    minHeap.emplace(num);
                    std::cout << "Top element replaced: " << minHeap.top() << std::endl;
                    std::cout << "Min Head size: " << minHeap.size() << std::endl;
                }
            }else{
                minHeap.emplace(num);
            }
        }
        return minHeap.top();
    }
};

int main(){
    std::vector<int> nums = {3,2,3,1,2,4,5,5,6};
    Solution solution;
    solution.findKthLargest(nums, 4);
}