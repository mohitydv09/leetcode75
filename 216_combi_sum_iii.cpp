#include<iostream>
#include<numeric>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> currList;

        for(int i = 1; i < 10; i++){
            currList.push_back(i);
            backTrack(i, currList, k, n, ans);
            currList.pop_back();
        }
        return ans;
    }

private:
    void backTrack(int last_char, vector<int>& currList, int k, int n, vector<vector<int>>& ans){
        // cout << "BT with last char as : " << last_char << " Level is : " << currList.size() << endl;
        // cout << "Size of currList     : " << currList.size() << endl;
        if(currList.size() == k){
            int list_sum = accumulate(currList.begin(), currList.end(), 0);
            if(list_sum == n){
                ans.push_back(currList);
                // cout << "Item added to CurrList " << endl;
                // currList.pop_back();
            }
            return;
        }else{
            if (last_char == 9){
                return;
            }else{
                for(int i = last_char + 1; i < 10; i++){
                    currList.push_back(i);
                    backTrack(i, currList, k, n, ans);
                    currList.pop_back();
                }
            }
        }
    }
};

int main(){
    Solution solution_instance;
    int k = 3;
    int n = 7;
    vector<vector<int>> ans = solution_instance.combinationSum3(k, n);
    return 0;
}