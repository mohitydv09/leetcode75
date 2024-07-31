#include <iostream>
#include <string>
#include <map>

class Solution{
public:
    int lengthOfLongestSubstring(std::string s){
        if(s.size() < 2){return s.size();};
        int maxLength = 0;
        int left = 0;
        int right = 0;
        std::map<char, int> hashMap;
        while(right < s.size()){
            if(hashMap[s[right]] > 0){
                if((right-left) > maxLength){
                    maxLength = right-left;
                }
                while(left < hashMap[s[right]]){
                    hashMap[s[left]] = 0;
                    left++;
                }
                hashMap[s[right]] = 0;
            }
            hashMap[s[right]] = right+1;
            right++;
        }
        if(right-left > maxLength){
            maxLength = right-left;
        }
        return maxLength;
    }
};

int main(){
    Solution solution;
    std::string s = "abba";
    int answer = solution.lengthOfLongestSubstring(s);
    std::cout << "Answer: " << answer << std::endl;
}