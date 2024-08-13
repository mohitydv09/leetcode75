#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution{
public:
    int minEatingSpeed(vector<int>& piles, int h){
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        int ans = 0;
        while (low<=high){
            double mid = (low+high)/2;
            long long time = timeRequired(piles, mid);
            if(time > h){
                low = mid + 1;
            }else if (time <= h){
                high = mid - 1;
                ans = mid;
            }
        }
        return ans;
    }

private:
    long long timeRequired(vector<int>& piles, double& k){
        long long time = 0;
        for(int pile : piles){
            time += ceil(pile/k);
        }
        return time;
    }
};

int main(){
    Solution solution_instance;
    vector<int> piles = {1000000000};
    int h = 2;
    cout << solution_instance.minEatingSpeed(piles, h) << endl;
}
