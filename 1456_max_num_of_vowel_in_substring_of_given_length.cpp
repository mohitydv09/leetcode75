#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxVowels(string s, int k) {
        int  vowel[s.size()];
        for (int i = 0; i < s.size(); i++){
            if(isVowel(s[i])){
                vowel[i] = 1;
            }else{
                vowel[i] = 0;
            }
        }

        int vowel_count = 0;
        for (int i = 0; i < k; i++){
            vowel_count += vowel[i];
        }

        int max_vowel = vowel_count;
        for (int i = 0; i < s.size() - k; i++){
            vowel_count -= vowel[i];
            vowel_count += vowel[i+k];
            if(vowel_count > max_vowel){
                max_vowel = vowel_count;
            }
        }
        return max_vowel;
    }

private:
    bool isVowel(char ch){
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }
};

int main(){
    Solution solution_instance;
    string str = "abciiidef";
    int k = 2;
    cout << solution_instance.maxVowels(str, k) << endl;
    return 0;
} 