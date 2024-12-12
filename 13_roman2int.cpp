#include<iostream>
#include<string>

class Solution {
public:
    int romanToInt(std::string s) {
        int answer = 0;
        for(int i = 0; i < s.size(); ++i){
            if(i < s.size()-1 && s[i] == 'I' && s[i+1] == 'V'){
                answer+= 4;
                ++i;
            }else if(i < s.size()-1 && s[i] == 'I' && s[i+1] == 'X'){
                answer+= 9;
                ++i;
            }else if(i < s.size()-1 && s[i] == 'X' && s[i+1] == 'L'){
                answer+= 40;
                ++i;
            }else if(i < s.size()-1 && s[i] == 'X' && s[i+1] == 'C'){
                answer+= 90;
                ++i;
            }else if(i < s.size()-1 && s[i] == 'C' && s[i+1] == 'D'){
                answer+= 400;
                ++i;
            }else if(i < s.size()-1 && s[i] == 'C' && s[i+1] == 'M'){
                answer+= 900;
                ++i;
            }else{
                answer+= char2int(s[i]);
            }
        }
        return answer;
    }

private:
    int char2int(char c){
        if( c == 'I'){
            return 1;
        }else if (c == 'V'){
            return 5;
        }else if (c == 'X'){
            return 10;
        }else if (c == 'L'){
            return 50;
        }else if (c == 'C'){
            return 100;
        }else if (c == 'D'){
            return 500;
        }else if (c == 'M'){
            return 1000;
        }else{
            return -1;
        }
    }
};

int main(){
    Solution solution;
    int answer = solution.romanToInt("MCMXCIV");  //MCMXCIV
    std::cout << "Answer: " << answer << std::endl;
}