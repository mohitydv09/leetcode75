#include<iostream>
#include<vector>

class Solution {
public:
    std::vector<int> plusOne(std::vector<int>& digits) {
        int carry = 1;
        for(int i = digits.size()-1; i >= 0; --i){
            if(digits[i] == 9){
                digits[i] = 0;
            }else{
                digits[i] += carry;
                return digits;
            }
        }
        std::vector<int> final_answer(digits.size() + 1, 0);
        final_answer[0] = 1;
        return final_answer;
    }
};

int main(){
    Solution solution;
    std::vector<int> digits = {9,9,9};
    std::vector<int> answer = solution.plusOne(digits);
    std::cout << "Answer: ";
    for (int item : answer){
        std::cout << item << " ";
    }
    std::cout << std::endl;
}