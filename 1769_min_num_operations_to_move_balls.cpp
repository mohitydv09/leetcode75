#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<map>
#include<set>
#include<string>

#include "utils.h"

using namespace std;

class Solution {
public:
    vector<int> minOperations(string boxes) {
        int left = 0;
        int right = 0;
        vector<int> answer(boxes.size(), 0);
        for(int i = 0; i < boxes.size(); ++i){
            if(boxes[i] == '1'){
                right++;
                answer[0] += i;
            }
        }
        for(int i = 1; i < boxes.size(); ++i){
            if(boxes[i-1] == '1'){
                left++;
                right--;
            }
            answer[i] = answer[i-1] - right + left;
        }
        return answer;
    }
};

int main(){
    Solution solution;
    vector<int> input = {};
    vector<int> answer = solution.minOperations("001011");
    cout << "Answer: " << endl;
    printVector(answer);
}