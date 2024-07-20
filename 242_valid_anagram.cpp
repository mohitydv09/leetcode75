#include <iostream>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()){
            return false;
        }
        map<char, int> s_count;
        map<char, int> t_count;
        for (int i = 0; i < s.size(); i++){
            s_count[s[i]]++;
            t_count[t[i]]++;
        }
        for (const auto& pair : s_count){
            if(s_count[pair.first] != t_count[pair.first]){
                return false;
            }
        }
        return true;
    }
};

int main(){
    Solution solution;
    string s = "anagram";
    string t = "nagaram";
    bool answer = solution.isAnagram(s, t);
    cout << answer << endl;
}