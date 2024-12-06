#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>

class Solution {
public:
    int maxCount(std::vector<int>& banned, int n, int maxSum) {
        std::vector<bool> banned_set(n+1, false);
        for(const int& item : banned){
            if(item <= n){
                banned_set[item] = true;
            }
        }
        int count = 0;
        int currSum = 0;
        for (int i = 1; i <= n; ++i){
            if(banned_set[i] == false){
                currSum += i;
                if (currSum > maxSum){
                    return count;
                }
                count++;
            }
        }
        return count;
    }
};

int main(){
    Solution solution;
    std::vector<int> banned = {1,5,6};
    int answer = solution.maxCount(banned, 5, 6);
    std::cout << "Answer: " << answer << std::endl;
}