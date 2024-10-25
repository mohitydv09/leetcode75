#include<iostream>
#include<string>

class Solution {
public:
    std::string longestPalindrome(std::string s) {
        std::string answer;
        int ansSize = 0;
        for(int i = 0; i < s.size(); ++i){
            int left = i, right = i;
            while (left >=0 && right < s.size() && s[left] == s[right]){
                if(right - left + 1 > ansSize){
                    answer = s.substr(left,right - left + 1);
                    ansSize = right - left + 1;
                }
                left--;
                right++;
            }

            left = i, right = i+1;
            while (left >=0 && right < s.size() && s[left] == s[right]){
                if(right - left + 1 > ansSize){
                    answer = s.substr(left,right - left + 1);
                    ansSize = right - left + 1;
                }
                left--;
                right++;
            }
        }
        return answer;
    }
};

int main(){
    Solution solution;
    std::string s = "babad";
    std::cout << "Answer: " << solution.longestPalindrome(s) << std::endl;
}