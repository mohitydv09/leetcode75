#include<iostream>
#include<string>

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t answer = 0;
        for (int i = 0; i < 32; ++i){
            int lsb = n & 1; // Get the Least Sig Bit
            answer = answer << 1; // Move the answer to left
            answer = answer | lsb; // add the lsb
            n = n >> 1; // move the n to right
        }
        return answer;
    }
};

int main(){
    Solution solution;
    uint32_t n = 43261596;
    uint32_t answer = solution.reverseBits(n);
    std::cout << "Answer: " << answer << std::endl;
}