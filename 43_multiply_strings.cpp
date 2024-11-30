#include<iostream>
#include<string>
#include<vector>
#include<sstream>

class Solution {
public:
    std::string multiply(std::string num1, std::string num2) {
        if(num1 == "0" || num2 == "0"){
            return "0";
        }

        std::vector<int> result(num1.size() + num2.size(), 0);
        for(int i = num1.size()-1; i >= 0; --i){
            for(int j = num2.size()-1; j >= 0; --j){
                int multi = (num2[j]-'0') * (num1[i]-'0');
                result[i + j + 1] += multi;
                result[i + j] += result[i + j + 1]/10;
                result[i + j + 1] = result[i + j + 1]%10;
            }
        }
        std::stringstream answer;
        int start = 0;
        while(result[start] == 0){
            start++;
        }
        for(int i = start; i < result.size(); ++i){
            answer << result[i];
        }
        return answer.str();
    }
};

int main(){
    Solution solution;
    std::string num1 = "123";
    std::string num2 = "456";
    std::string answer = solution.multiply(num1, num2);
    std::cout << "Answer: " << answer << std::endl;
}