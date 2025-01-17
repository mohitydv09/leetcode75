#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<map>
#include<set>
#include<string>
#include<algorithm>
#include<numeric>

#include "utils.h"

using namespace std;

class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        return accumulate(derived.begin(), derived.end(), 0, bit_xor<int>()) == 0;
    }
};

int main(){
    Solution solution;
    vector<int> input = {1,1,0};
    bool answer = solution.doesValidArrayExist(input);
    cout << "Answer: " << answer << endl;
}