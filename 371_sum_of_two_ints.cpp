#include<iostream>

class Solution {
public:
    int getSum(int a, int b) {
        int currSum = a ^ b;
        int carry = a & b;
        carry <<= 1;
        while(carry != 0){
            int temp = currSum;
            currSum = currSum ^ carry;
            carry = carry & temp;
            carry <<= 1;
        }
        return currSum;
    }
};

int main(){
    Solution solution;
    int answer = solution.getSum(5, 3);
    std::cout << "Answer: " << answer << std::endl;
}