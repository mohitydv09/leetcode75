#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        vector<int> ans(spells.size(), 0);

        for (int i = 0; i < spells.size(); i++){
            int low = 0;
            int high = potions.size() - 1;
            int first_idx = potions.size();

            while(low <= high){
                int mid = (low + high)/2;
                long long spell_val = spells[i];
                long long potion_val = potions[mid];
                if(spell_val*potion_val >= success){
                    high = mid - 1;
                    first_idx = mid;
                }else{
                    low = mid + 1;
                }
            }
            ans[i] = potions.size() - first_idx;
        }
        return ans;
    }
};

int main(){
    Solution solution_instance;
    vector<int> spells = {3,1,2};
    vector<int> potions = {8,5,8};
    long long success = 16;
    vector<int> ans = solution_instance.successfulPairs(spells, potions, success);

    cout << "ans : " ;
    for(int item : ans){
        cout << item << " " ;;
    }
    cout << endl;

}