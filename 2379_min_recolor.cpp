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
        int minimumRecolors(string blocks, int k) {
            int countW = 0;
            for(int i = 0 ; i < k; ++i){
                if(blocks[i] == 'W'){
                    countW++;
                }
            }
            int minW = countW;
            int left = 0;
            int right = k;
            while(right < blocks.size()){
                if(blocks[right] == 'W'){
                    countW++;
                }
                if(blocks[left] == 'W'){
                    countW--;
                }
                left++;
                right++;
                cout << "Value of countW: " << countW << endl;
                minW = min(minW, countW);
            }
            return minW;
        }
    };

int main(){
    Solution solution;
    string input = "WBWBBBW";
    int answer = solution.minimumRecolors(input, 2);
    cout << "Answer: " << answer << endl;
}