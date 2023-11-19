#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int capacity = 0;
        if (flowerbed.size() < 2 && flowerbed[0]==0){
                capacity++;
        } else{
            if (flowerbed[0] == 0 && flowerbed[1]==0){
                capacity+=1;
                flowerbed[0]=1;
            }
            for (int i = 1 ; i <flowerbed.size()-1; i++){
                cout << "Running For:" << i << endl;
                if ((flowerbed[i]==0) && (flowerbed[i-1]==0) && (flowerbed[i+1]==0)){
                    cout << i << endl;
                    flowerbed[i] = 1;
                    capacity ++;
                    i++;
                }
                cout << "code ran" << endl;
            }
            if (flowerbed[flowerbed.size()-1] == 0 && flowerbed[flowerbed.size()-2] == 0){
                flowerbed[flowerbed.size()-1] = 1;
                capacity++;
            }
        }
        cout << "Capacity:" << capacity << endl;
        if (capacity >= n){
            return true;
        }else{
            return false;
        }
    }
};

int main(){
    Solution solution_instance;
    vector<int> flowerbed = {0,1};
    cout << solution_instance.canPlaceFlowers(flowerbed, 1 ) << endl;
    // cout << solution_instance.kidsWithCandies(candies, 5 );
    return 0;
} 