#include<iostream>
#include<vector>
#include<queue>

class KthLargest {
int heapSize;
std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
public:
    KthLargest(int k, std::vector<int>& nums) {
        // Add everything to the heap.
        heapSize = k;
        for(int num : nums){
            minHeap.emplace(num);
        }
        while(minHeap.size() > k){
            minHeap.pop();
        }
    }
    
    int add(int val) {
        minHeap.emplace(val);
        while(minHeap.size() > heapSize){
            minHeap.pop();
        }
        return minHeap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

int main(){
    int k = 3;
    std::vector<int> nums = {4, 5, 8, 2};
    KthLargest* obj = new KthLargest(k, nums);
    int param_1 = obj->add(3);
    std::cout << "Param 1: " << param_1 << std::endl;
}