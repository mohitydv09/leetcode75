#include<iostream>
#include<string>

class Solution {
public:
    bool checkValidString(std::string s) {
        int min = 0;
        int max = 0;
        for(int i = 0; i < s.size(); ++i){
            if(s[i] == '('){
                min++;
                max++;
            }else if(s[i] == ')'){
                min--;
                max--;
                if(max < 0){
                    return false;
                }
            }else{
                min--;
                max++;
            }
            min = std::max(0, min);
        }
        return min == 0;
    }
};

int main(){
    Solution solution;
    bool answer = solution.checkValidString("(*))");
    std::cout << "Answer: " << answer << std::endl;
}