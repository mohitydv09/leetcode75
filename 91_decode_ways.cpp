#include<iostream>
#include<string>
#include<vector>

class Solution {
public:
    int numDecodings(std::string s) {
        if(s[0] == '0'){return 0;};
        std::vector<int> answer(s.size()+1, 1);
        if(s[s.size()-1] == '0'){answer[s.size()-1] = 0;}
        for(int i = s.size()-2; i >= 0; --i){
            if(s[i] == '0'){
                answer[i] = 0;
            }else{
                answer[i] = answer[i+1];
            }
            // When we pick two.
            // Can we form two.
            if(s[i] == '1' || (s[i] == '2' && s[i+1] - '0' <= 6)){
                answer[i] += answer[i+2];
            }
        }
        std::cout << "Answer array: ";
        for (auto item : answer){
            std::cout << item << " "; 
        } 
        std::cout << std::endl;
        return answer[0];
    }
};

int main(){
    Solution solution;
    std::string s = "12";
    std::cout << "Answer: " << solution.numDecodings(s) << std::endl;
}