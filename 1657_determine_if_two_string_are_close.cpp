#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        // Case when size of both strings is unequal.
        if(word1.size() != word2.size()) { return false; }

        // Make hash table to count occurances.
        unordered_map<char, int> word1_map;
        unordered_map<char, int> word2_map;
        for( char c : word1){
            word1_map[c] += 1;
        }
        for( char c : word2){
            word2_map[c] += 1;
        }

        // Placeholder vector for storing the value of occurances.
        vector<char> word1_chars;
        vector<int> word1_counts;
        vector<char> word2_chars;
        vector<int> word2_counts;

        for(auto i = word1_map.begin(); i != word1_map.end(); i++){
            word1_chars.push_back(i->first);
            word1_counts.push_back(i->second);
        }
        for(auto i = word2_map.begin(); i != word2_map.end(); i++){
            word2_chars.push_back(i->first);
            word2_counts.push_back(i->second);
        }

        // Sort both the vectors.
        sort(word1_chars.begin(),word1_chars.end());
        sort(word1_counts.begin(),word1_counts.end());
        sort(word2_chars.begin(),word2_chars.end());
        sort(word2_counts.begin(),word2_counts.end());

        if ( word1_chars == word2_chars && word1_counts == word2_counts){
            return true;
        }else{
            return false;
        }
    }
};

int main(){
    Solution solution_instance;
    string word1 = "aaabc";
    string word2 = "bcaaa";
    cout << solution_instance.closeStrings(word1, word2);
    return 0;
} 