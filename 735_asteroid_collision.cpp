#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int>result;
        for(int i = 0; i < asteroids.size(); i++){
            if(result.empty()){
                result.push_back(asteroids[i]);
            }else if (asteroids[i] > 0 || (asteroids[i] < 0 && result.back() < 0)){
                result.push_back(asteroids[i]);
            }else{
                // incoming is negetive and last is positive
                while(true){
                    if(result.empty()){
                        result.push_back(asteroids[i]);
                        break;
                    }else if(result.back() < 0){
                        result.push_back(asteroids[i]);
                        break;
                    }else if(result.back() == abs(asteroids[i])){
                        result.pop_back();
                        break;
                    }else if(result.back() > abs(asteroids[i]) ){
                        break;
                    }else{
                        result.pop_back();
                    }
                }

            }
            cout << "This is the new result " << endl;
            for (int item : result){
                cout << item << " ";
            }
            cout << endl;
        }
        return result;
    }
};

int main(){
    Solution solution_instance;
    vector<int> aster = {-2,-2,1,-2};
    solution_instance.asteroidCollision(aster);
    return 0;
} 