#include<iostream>

using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        
        auto comparator = [](vector<int>& a , vector<int>& b){
            if(a[0] == b[0]){
                return a[1] < b[1];
            }else{
                return a[0] < b[0];
            }
        };

        sort(points.begin(), points.end(), comparator);
        
        int ans = 1;
        int currEnd = points[0][1];
        for (int i = 1; i < points.size(); i++){
            if(points[i][0] <= currEnd && points[i][1] < currEnd){
                // ans++;
                currEnd = points[i][1];
            }else if (points[i][0] <= currEnd){
                continue;
            }else{
                ans++;
                currEnd = points[i][1];
            }
        }
        return ans;
    }
};

int main(){
    Solution obj;
    vector<vector<int>> points = {{10,16},{2,8},{1,6},{7,12}};
    cout << obj.findMinArrowShots(points) << endl;
};