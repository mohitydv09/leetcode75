#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<map>
#include<set>
#include<algorithm>
#include<string>

#include "utils.h"

using namespace std;

class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        vector<int> diffArray(s.size()+1,0);
        for(const auto& shift : shifts){
            diffArray[shift[0]] += (shift[2] == 1) ? 1 : -1;
            diffArray[shift[1] + 1] -= (shift[2] == 1) ? 1 : -1;
        }
        int currChange = 0;
        for(int i = 0; i < s.size(); ++i){
            currChange += diffArray[i];
            cout << " Val: " << s[i] - 'a' + currChange << endl;
            int changeVal = ((s[i] - 'a' + currChange)%26 + 26)%26;
            s[i] = 'a' + changeVal;
        }
        return s;
    }
};

int main(){
    Solution solution;
    vector<vector<int>> shifts = {{4,8,0},{4,4,0},{2,4,0},{2,4,0},{6,7,1},{2,2,1},{0,2,1},{8,8,0},{1,3,1}};
    string answer = solution.shiftingLetters("xuwdbdqik", shifts);
    cout << "Answer: " << answer << endl;
}