#include<iostream>
#include<map>

class Solution{
public:
    int characterReplacement(std::string s, int k){
        std::map<char, int> hashMap;
        int left = 0;
        int right = 0;
        int answer = 0;
        hashMap[s[right]]++;
        while(right < s.size()){
            int maxValue = INT_MIN;
            for(const auto& pair : hashMap){
                if (pair.second > maxValue){
                    maxValue = pair.second;
                }
            }
            std::cout << "Max Value is: " << maxValue << std::endl;
            int windowSize = right - left + 1;
            std::cout << "window size is: " << windowSize << std::endl;
            if(maxValue + k >= windowSize){
                // Valid string move right.
                right++;
                hashMap[s[right]]++;
                if(windowSize > answer){
                    answer = windowSize;
                }
            }else{
                hashMap[s[left]]--;
                left++;
            }
        }
        return answer;
    }
};

int main(){
    Solution solution;
    std::string s = "AABABBA";
    int k = 1;
    int answer = solution.characterReplacement(s, k);
    std::cout << "Answer: " << answer << std::endl;
}