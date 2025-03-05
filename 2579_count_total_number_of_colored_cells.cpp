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
    long long coloredCells(int n) {
        long long ans = 1;
        for(int i = 2; i <= n; ++i){
            ans += 4*(i-1);
        }
        return ans;
    }
};

int main(){
    Solution solution;
    int input = 5;
    int answer = solution.coloredCells(input);
    cout << "Answer: " << answer << endl;
}