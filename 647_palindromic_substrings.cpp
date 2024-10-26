#include<iostream>
#include<string>

class Solution {
public:
    int countSubstrings(std::string s) {
        int count = 0;
        for(int i = 0; i < s.size(); ++i){
            int left = i;
            int right = i;
            while(left >= 0 && right < s.size() && s[left]==s[right]){
                count++;
                left--;
                right++;
            }
            left = i;
            right = i + 1;
            while(left >= 0 && right < s.size() && s[left]==s[right]){
                count++;
                left--;
                right++;
            }
        }
        return count;
    }
};

int main(){
    Solution solution;
    std::string s = "aaa";
    std::cout << "Answer: " << solution.countSubstrings(s) << std::endl;
}