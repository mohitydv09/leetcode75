#include<iostream>
#include<vector>

class Solution {
public:
    int maxChunksToSorted(std::vector<int>& arr) {
        int chunks = 0;
        int currMax = 0;
        for(int i = 0; i < arr.size(); ++i){
            currMax = std::max(currMax, arr[i]);
            if(i == currMax){
                chunks++;
                currMax = 0;
            }
        }
        return chunks;
    }
};

int main(){
    Solution solution;
    std::vector<int> arr = {2,3,1,0,4};
    int answer = solution.maxChunksToSorted(arr);
    std::cout << "Answer: " << answer << std::endl;
}