#include <iostream>
#include <vector>
#include <stack>
#include <cctype>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
        // make a string to store the result.
        string stack;
        for (char c : s){
            if( c != ']' ){
                // Just add to the stack.
                stack += c;
            }else{
                // Bracket ended remove from stack item and put in string.
                string sub_string;
                while(stack.back() != '['){
                    sub_string += stack.back();
                    stack.pop_back();
                }
                reverse(sub_string.begin(), sub_string.end());
                cout << "sub string is : " << sub_string << endl;

                // Remove the bracket
                stack.pop_back();
                string k_string;
                while(isdigit(stack.back())){
                    k_string += stack.back();
                    stack.pop_back();
                    if(stack.empty()){
                        break;
                    }
                }
                reverse(k_string.begin(),k_string.end());
                int k = stoi(k_string);
                for( int i = 0; i < k; i++){
                    stack += sub_string;
                }
            }
        }
        cout << "At last stack is : " << stack << endl;
        return stack;
    }
};

int main(){
    Solution solution_instance;
    string s = "2[abc]3[cd]ef";
    cout << solution_instance.decodeString(s);
    return 0;
} 