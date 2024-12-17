#include<iostream>
#include<vector>
#include<string>

class Solution {
public:
    std::string repeatLimitedString(std::string s, int repeatLimit) {
        std::vector<int> numOcc(26, 0);
        for(const char& c : s){
            numOcc[c-'a']++;
        }
        std::string answer;
        int idx = 25;
        while(idx >= 0){
            while(numOcc[idx] == 0){
                idx--;
                if(idx < 0){return answer;}
            }
            int numToAdd = std::min(numOcc[idx], repeatLimit);
            for(int i = 0; i < numToAdd; ++i){
                answer.push_back(idx + 'a');
                numOcc[idx]--;
            }

            if(numOcc[idx] > 0){ //still left
                int idx2 = idx - 1;
                if(idx2 < 0){return answer;}
                while(numOcc[idx2] == 0){
                    idx2--;
                    if(idx2 < 0){return answer;}
                }
                answer.push_back(idx2 + 'a');
                numOcc[idx2]--;
            }
        }
        return answer;
    }
};

int main(){
    Solution solution;
    std::string answer = solution.repeatLimitedString("aababab", 2);
    std::cout << "Answer: " << answer << std::endl;
}