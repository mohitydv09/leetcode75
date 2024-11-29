#include<iostream>

class Solution {
public:
    double myPow(double x, int n) {
        if(x==0){return x;}
        if(x==1){return x;}
        if(n==0){return 1;}
        
        long long newN = n;
        if(newN < 0){
            newN = -newN;
            x = 1/x;
        }
        double ans = 1.0;
        while(newN > 0){
            if(newN %2 == 1){
                ans *= x;
            }
            x *= x;
            newN /= 2;
        }
        return ans;
    }
};

int main(){
    Solution solution;
    double answer = solution.myPow(2.00, -2147483648);
    std::cout << "Answer: " << answer << std::endl;
}