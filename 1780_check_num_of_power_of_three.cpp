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
        bool checkPowersOfThree(int n) {
            for(int i = 16; i >= 0; --i){
                int raised = pow(3,i);
                if(n >= raised){
                    n -= raised;
                }
            }
            return (n == 0);
        }
};

int main(){
    Solution solution;
    int answer = solution.checkPowersOfThree(12);
    cout << "Answer: " << answer << endl;
}