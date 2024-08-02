#include<iostream>
#include<map>

class Solution{
public:
    bool checkInclusion(std::string s1, std::string s2) {
        if(s1.size() > s2.size()){
            return false;
        }
        int left = 0;
        int right = 0;
        std::map<char, int> hashMapSmaller;
        std::map<char, int> hashMapLarger;
        for (char c : s1){
            hashMapSmaller[c]++;
        }
        while(right < s1.size()){
            hashMapLarger[s2[right]]++;
            right++;
        }
        if(hashMapLarger == hashMapSmaller){
            return true;
        }

        while(right < s2.size()){
            std::cout << "larget Hashmap : " << std::endl;
            for(auto pair : hashMapLarger){
                std::cout << pair.first << " " << pair.second << std::endl;
            }
            std::cout << "Smaller Hashmap : " << std::endl;
            for(auto pair : hashMapSmaller){
                std::cout << pair.first << " " << pair.second << std::endl;
            }
            if(hashMapLarger[s2[left]] == 1){
                hashMapLarger.erase(s2[left]);
            }else{
                hashMapLarger[s2[left]]--;
            }
            hashMapLarger[s2[right]]++;

            if(hashMapLarger == hashMapSmaller){
                return true;
            }
            left++;
            right++;
        }
        return false;
    }
};

int main(){
    Solution solution;
    std::string s1 = "ab";
    std::string s2 = "eidboaoo";
    bool answer = solution.checkInclusion(s1, s2);
    std::cout << "Answer: " << answer << std::endl;
}