#include<iostream>
#include<vector>
#include<algorithm>

class Solution {
public:
    int hIndex(std::vector<int>& citations) {
        if(citations.size() == 1){return std::min(1, citations[0]);};
        std::sort(citations.begin(), citations.end(), std::greater<int>());
        int i = 0;
        while(i+1 < citations.size() && i+1 <= citations[i]){
            ++i;
        }
        return i;
    }
};

int main(){
    Solution solution;
    std::vector<int> citations = {11,15};
    int answer = solution.hIndex(citations);
    std::cout << "Answer: " << answer << std::endl;
}