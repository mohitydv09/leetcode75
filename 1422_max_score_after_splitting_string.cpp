#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    int maxScore(string s) {
        int onces = 0;
        for(const char& c : s){
            if(c == '1'){onces++;}
        }
        int answer = 0;
        int a = 0;
        for(int i = 0; i < s.size()-1; ++i){
            if(s[i] == '0'){
                a+=1;
            }else{
                onces--;
            }
            cout << "a: " << a << " b: " << onces<< endl;
            answer = max(answer, a + onces);
        }
        return answer;
    }
};

int main(){
    Solution solution;
    int answer = solution.maxScore("011101");
    cout << "Answer: " << answer << endl;
}