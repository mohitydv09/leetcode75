#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<map>
#include<set>
#include<string>
#include<algorithm>

#include "utils.h"

using namespace std;

class Solution {
public:
    int minimizeXor(int num1, int num2) {

        int answer = num1;
        int setBitsAnswer = __builtin_popcount(answer);
        int setBitsNum2 = __builtin_popcount(num2);

        int currBit = 0;
        while(setBitsAnswer < setBitsNum2){
            if(!isSet(answer, currBit)){
                bitSet(answer, currBit);
                setBitsAnswer++;
            }
            currBit++;
        }

        while(setBitsAnswer > setBitsNum2){
            if(isSet(answer, currBit)){
                unSet(answer, currBit);
                setBitsAnswer--;
            }
            currBit++;
        }
        return answer;
    }
private:
    bool isSet(int& num, int& position){
        return num & (1 << position);
    }
    void bitSet(int& num, int& position){
        num = num | (1 << position);
    }
    void unSet(int& num, int& position){
        num = num & ~(1 << position);
    }
};

int main(){
    Solution solution;
    int answer = solution.minimizeXor(25, 72);
    cout << "Answer: " << answer << endl;
}