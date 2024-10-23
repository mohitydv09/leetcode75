#include<iostream>

class Solution {
public:
    int climbStairs(int n) {
        if(n == 1){return 1;}
        if(n == 2){return 2;}
        int secondLast = 1;
        int last = 2;
        int ans;
        for(int i = 2; i < n; ++i){
            ans = last + secondLast;
            secondLast = last;
            last = ans;
        }
        return ans;
    }
};

int main(){
    Solution solution;
    std::cout << "Answer: " << solution.climbStairs(45) << std::endl;
}