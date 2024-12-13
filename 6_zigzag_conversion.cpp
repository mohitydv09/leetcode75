#include<iostream>
#include<string>

class Solution {
public:
    std::string convert(std::string s, int numRows) {
        if(numRows == 1){return s;}
        std::string answer;
        for(int i = 0; i < numRows; ++i){
            int j = i;
            while(j < s.size()){
                answer.push_back(s[j]);
                int next = j + 2*(numRows-1-i);
                if(i != 0 && i != numRows-1 && next < s.size()){
                    answer.push_back(s[next]);
                }
                j += 2*(numRows-1);
            }
        }
        return answer;
    }
};

int main(){
    Solution solution;
    std::string s = "mohityadav";
    std::string answer = solution.convert(s, 3);
    std::cout << "Answer: " << answer << std::endl;
}