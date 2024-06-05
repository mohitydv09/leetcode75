#include<iostream>

using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1, 0);
        if(n == 0){
            return ans;
        }else if(n == 1){
            ans[1] = 1;
            return ans;
        }
        ans[0] = 0;
        ans[1] = 1;
        int curr2power = 2;
        for(int i = 2; i <= n; i++){
            if(i%curr2power == 0){
                curr2power = i;
            }
            ans[i] = 1 + ans[i-curr2power];
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
    Solution solution_instance;
    int n = 10;
    vector<int> ans = solution_instance.countBits(n);
}