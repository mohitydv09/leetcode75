#include<iostream>
#include<vector>

class Solution {
public:
    bool mergeTriplets(std::vector<std::vector<int>>& triplets, std::vector<int>& target) {
        std::vector<bool> ans(3, false);
        for(const auto& triplet : triplets){
            if(triplet[0] > target[0] || triplet[1] > target[1] || triplet[2] > target[2]){
                continue;
            }
            if(triplet[0] == target[0]) ans[0] = true;
            if(triplet[1] == target[1]) ans[1] = true;
            if(triplet[2] == target[2]) ans[2] = true;
            if(ans[0] && ans[1] && ans[2]){
                return true;
            }
        }
        return ans[0] && ans[1] && ans[2];
    }
};

int main(){
    Solution solution;
    std::vector<std::vector<int>> triplets = {{3,4,5},{4,5,6}};
    std::vector<int> target = {3,2,5};
    bool answer = solution.mergeTriplets(triplets, target);
    std::cout << "Answer: " << answer << std::endl;
}