#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> result;
        int max_item = *max_element(candies.begin(), candies.end());
        for ( int i=0 ; i < candies.size() ; i++){
            if (candies[i] + extraCandies >= max_item){
                result.push_back(true);
            } else{
                result.push_back(false);
            }
        }
        return result;
    }
};

int main(){
    Solution solution_instance;
    solution_instance.kidsWithCandies({2,3,5,8}, 5 );
    // cout << solution_instance.kidsWithCandies(candies, 5 );
    return 0;
}