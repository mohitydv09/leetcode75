#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int front = 0;
        int back = s.size();
        while(front < back){
            if(!iswalnum(s[front])){
                front++;
                continue;
            }
            if(!iswalnum(s[back])){
                back--;
                continue;
            }
            if(tolower(s[front]) != tolower(s[back])){
                return false;
            }else{
                front++;
                back--;
            }

        }
        return true;
    }
};

int main(){
    Solution solution;
    string input_ = "A man, a plan, a canal: Panama";
    bool answer = solution.isPalindrome(input_);
    cout << "Answer: " << answer << endl;
}