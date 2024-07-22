#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> answer;
        map<vector<int>, vector<string>> hashMap;
        for (const string& str : strs){
            vector<int> string_key(26, 0);
            for (const char& c : str){
                string_key[c-'a']++; 
            }
            hashMap[string_key].push_back(str);
        }
        for(auto pair : hashMap){
            vector<string> group;
            for (auto similar_string : pair.second){
                group.push_back(similar_string);
            }
            answer.push_back(group);
        }
        cout << answer.size() << endl;
        return answer;
    }
};

int main(){
    Solution solution;
    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};
    vector<vector<string>> answer = solution.groupAnagrams(strs);
    cout << "Answer: " << endl;
    for (auto item : answer){
        cout << "Group: " << endl;
        for (auto item2 : item){
            cout << item2 << " ";
        }
    }

}
