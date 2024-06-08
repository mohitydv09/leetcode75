#include<iostream>
#include<stack>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans(temperatures.size(),0);
        stack<pair<int, int>> monoStack; // first is temp, second in index.

        // keep the first item in stack.
        monoStack.push({temperatures[0], 0});

        for (int i = 1; i < temperatures.size(); i++){
            // if the current temp is greater that top of stack that means we found the next high temp.
            auto topStack = monoStack.top();
            while(topStack.first < temperatures[i]){
                ans[topStack.second] = i - topStack.second;
                monoStack.pop();
                if(!monoStack.empty()){
                    topStack = monoStack.top();
                }else{
                    break;
                }
            }
            // Add the curr item to top of stack
            monoStack.push({temperatures[i],i});
        }

        cout << "Ans : ";
        for(int item : ans){
            cout << item << " ";
        }
        cout << endl;
        return ans;
    }
};

int main(){
    Solution obj;
    vector<int> temperatures = {73,74,75,71,69,72,76,73};
    vector<int> ans = obj.dailyTemperatures(temperatures);
    return 0;
}