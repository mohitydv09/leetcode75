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
    bool canConstruct(string s, int k) {
        if(s.size() < k){
            return false;
        }
        int counter[26]= {0};
        for(const char& c : s){
            counter[c-'a']++;
        }
        int count = 0;
        for(const int& i : counter){
            if(i % 2 == 1){
                count++;
            }
        }
        cout << "Count" << count << endl;
        return count <= k;
    }
};

int main(){
    Solution solution;
    bool answer = solution.canConstruct("cr", 7);
    cout << "Answer: " << answer << endl;
}