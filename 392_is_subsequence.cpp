#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        // To iterate inside s.
        int index_t = 0;
        int count = 0;
        // Iterate inside s.
        for(int i = 0; i < s.size(); i++){
            // Interater inside t.
            for (int j = index_t; j < t.size(); j++){
                if (s[i] == t[j]){
                    index_t = j+1;
                    count++;
                    break;
                }
            }
        }
        if (count == s.size()){
            return true;
        }else{
            return false;
        }
    }

};

int main(){
    Solution solution_instance;
    string s = "abcd";
    string t = "ahbagdc";
    cout << solution_instance.isSubsequence(s,t) << endl;
    return 0;
}