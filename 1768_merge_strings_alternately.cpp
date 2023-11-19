#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string result_string = "";
        int i=0;
        int j=0;
        for (int k = 0 ; k <= word1.length()+ word2.length() ;k++){
            if(i < word1.length()){
                result_string += word1[i];
            }
            if(j<word2.length()){
            result_string += word2[j];
            }
            i++;
            j++;
        }
    return result_string;
    }
};

int main(){
    Solution solution_insatance;
    cout << solution_insatance.mergeAlternately("mohit","yadav");
    return 0;
}