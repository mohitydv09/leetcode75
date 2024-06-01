#include <iostream>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.size() == 0){
            return ans;
        }
        unordered_map<char, string> int2chars;
        int2chars['2'] = "abc";
        int2chars['3'] = "def";
        int2chars['4'] = "ghi";
        int2chars['5'] = "jkl";
        int2chars['6'] = "mno";
        int2chars['7'] = "pqrs";
        int2chars['8'] = "tuv";
        int2chars['9'] = "wxyz";

        backTrack(0, "", digits, int2chars, ans);

        return ans;
    }

private:
    void backTrack(int idx, string currString, string &digits, unordered_map<char, string> &int2chars, vector<string> &ans){
        if(idx == digits.size()){
            ans.push_back(currString);
            // cout << "Pushed back to ans : " << currString << endl;
            currString.pop_back();
            return;
        }
        string chars4digit = int2chars[digits[idx]];
        for (int i = 0; i < chars4digit.size(); i++){
            currString += chars4digit[i];
            backTrack(idx + 1, currString, digits, int2chars, ans);
            currString.pop_back();
        }
        return;
    }
};

int main(){
    Solution solution_instance;
    string digits = "23";
    vector<string> ans = solution_instance.letterCombinations(digits);
    for(string item : ans){
        cout << "Item : " << item << endl;
    }
    return 0;
}