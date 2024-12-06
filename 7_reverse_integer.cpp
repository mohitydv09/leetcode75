#include<iostream>
#include<climits>

class Solution {
public:
    int reverse(int x) {
        if(x == INT_MAX || x == INT_MIN){
            return 0;
        }
        int ans = 0;
        int sign = 1;
        if(x < 0){
            sign *= -1;
            x *= -1;
        }
        while(x > 0){
            if(ans > INT_MAX/10){
                return 0;
            }
            ans *= 10;
            int currdigit = x%10;
            x /= 10;
            ans += currdigit;
        }
        return sign*ans;
    }
};

int main(){
    Solution solution;
    int answer = solution.reverse(1534236469);
    std::cout << "Answer: " << answer << std::endl;
}