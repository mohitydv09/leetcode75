#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    string removeStars(string s) {
        // Declare a new string.
        string my_string;
        for(int i = 0; i < s.size(); i++){
            if (s[i] == '*'){
                my_string.pop_back();
            }else{
                my_string.push_back(s[i]);
            }
        }
        return my_string;
    }
};

int main(){
    Solution solution_instance;
    string s = "leet**cod*e";
    cout << solution_instance.removeStars(s);
    return 0;
} 