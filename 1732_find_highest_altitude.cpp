#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int max_altitude = 0;
        int curr_altitude = 0;
        for (int i = 0; i < gain.size(); i++){
            curr_altitude += gain[i];
            if(curr_altitude > max_altitude){
                max_altitude = curr_altitude;
            }
        }
        return max_altitude;
    }
};

int main(){
    Solution solution_instance;
    vector<int> gain = {-4,-3,-2,-1,4,3,2};
    cout << solution_instance.largestAltitude(gain) << endl;
    return 0;
} 