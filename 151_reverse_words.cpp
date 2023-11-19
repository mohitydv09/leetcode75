#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        stringstream words_in_string(s);

        // Initialize empty vector to store words.
        vector<string> words;
        string word;

        while(words_in_string >> word){
            words.push_back(word);
            // cout << word << endl;
        }

        string out_string;
        for(int i = words.size()-1 ; i >= 0 ; i--){
            out_string = out_string + words[i] + " ";
        }
        if(!out_string.empty()){
            out_string.pop_back();
        }
        cout << out_string << endl;
        return out_string;
    }
};

int main(){
    Solution solution_instance;
    cout << solution_instance.reverseWords("This is a trail string") << endl;
    return 0;
}