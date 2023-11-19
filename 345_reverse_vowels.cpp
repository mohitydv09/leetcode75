#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        vector<int> vowels;
        for ( int i=0; i< s.length(); i++){
            if (is_vowel(s[i])){
                vowels.push_back(i);
            }
        }
        int num_vowels = vowels.size();
        for ( int i = 0; i < num_vowels/2 ; i++){
            swap(s[vowels[i]], s[vowels[num_vowels-1-i]]);
        }
        return s;
    }

    bool is_vowel(char x){
        if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u' || x == 'A' || x == 'E' || x == 'I' || x == 'O' || x == 'U'){
            return true;
        } else {
            return false;
        }
    }
};

int main(){
    Solution solution_instance;
    cout << solution_instance.reverseVowels("mohit") << endl;
    return 0;
} 