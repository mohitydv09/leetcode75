#include<iostream>
#include<stack>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> answer(temperatures.size(), 0);
        stack<int> stk;
        //Push the first elements index.
        stk.push(0);
        for (int i = 1; i < temperatures.size(); ++i){
            while(stk.size() > 0 && temperatures[stk.top()] < temperatures[i]){
                answer[stk.top()] = i - stk.top();
                stk.pop();
            }
            stk.push(i);
        }
        cout << "answer: " << endl;
        for (int item : answer){
            cout << item << " " << endl;
        }
        return answer;
    }
};

// answer = [1,1,4,2,1,1,0,0]

int main(){
    Solution solution;
    vector<int> temperatures = {73,74,75,71,69,72,76,73};
    vector<int> ans = solution.dailyTemperatures(temperatures);
    return 0;
}