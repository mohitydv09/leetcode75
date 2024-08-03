#include <iostream>
#include <map>

class Solution{
public:
    std::string minWindow(std::string s, std::string t) {
        if(t.size() > s.size()){
            return "";
        }
        std::map<char, int> smallMap;
        for (const char& c : t){
            smallMap[c]++;
        }
        int required_conditions = smallMap.size();
        int satisfied_conditions = 0;
        int left = 0;
        int right = 0;
        int answer_left = 0;
        int answer_right = 0;
        int answer_size = INT_MAX;
        std::map<char, int> largeMap;
        while(smallMap[s[right]] == 0){
            right++;
            left++;
            if(right == s.size()){
                return "";
            }
        }
        largeMap[s[right]]++;
        if(largeMap[s[right]] == smallMap[s[right]]){
            satisfied_conditions++;
        }
        while(right < s.size()){
            std::cout << "In while loop checking for: " << s.substr(left, right - left + 1) << std::endl;
            std::cout << "Satisfied Conds: " << satisfied_conditions << std::endl;
            std::cout << "Required Conds: " << required_conditions << std::endl;
            if(satisfied_conditions < required_conditions){
                right++;
                if(smallMap[s[right]] > 0){
                    largeMap[s[right]]++;
                    if(largeMap[s[right]] == smallMap[s[right]]){
                        satisfied_conditions++;
                    }
                }
            }else{
                // As condition is satified we check if this is answer.
                if(right - left + 1 < answer_size){
                    answer_left = left;
                    answer_right = right;
                    answer_size = answer_right - answer_left + 1;
                }
                if(smallMap[s[left]] > 0){
                    if(largeMap[s[left]] == smallMap[s[left]]){
                        satisfied_conditions--;
                    }
                    if(largeMap[s[left]] == 1){
                        largeMap.erase(s[left]);
                    }else{
                        largeMap[s[left]]--;
                    }
                }
                left++;
            }
        }
        if(answer_size == INT_MAX){
            return "";
        }
        return s.substr(answer_left, answer_right - answer_left + 1);
    }
};

int main(){
    Solution solution;
    std::string s = "a";
    std::string t = "b";
    std::cout << solution.minWindow(s, t) << std::endl;
}