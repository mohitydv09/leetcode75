#include<iostream>
#include<vector>

class Solution {
public:
    std::vector<int> partitionLabels(std::string s) {
        std::vector<int> answer;
        int hashMap[26];
        for(int i = 0; i < s.size(); ++i){
            hashMap[s[i] - 'a'] = i;
        }
        int endIdx = 0;
        int currLen = 0;
        for(int i = 0; i < s.size(); ++i){
            int currIdx = hashMap[s[i] - 'a'];
            endIdx = std::max(currIdx, endIdx);
            currLen++;
            if(i == endIdx){
                answer.push_back(currLen);
                currLen = 0;
            }
        }
        return answer;
    }
};

int main(){
    Solution solution;
    std::string s = "ababcbacadefegdehijhklij";
    std::vector<int> answer = solution.partitionLabels(s);
    std::cout << "Answer: ";
    for (int item : answer){
        std::cout << item << " ";
    }
    std::cout << std::endl;
}