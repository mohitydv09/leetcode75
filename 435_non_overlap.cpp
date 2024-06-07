#include<iostream>

using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {

        auto comparator = [](vector<int>& a, vector<int>& b){
            if(a[0] == b[0]){
                return a[1] < b [1];
            }else{
                return a[0] < b[0];
            }
        };

        // Sort according to the first element in vects.
        sort(intervals.begin(), intervals.end(), comparator);

        // Go in loop to find the comparator.
        int ans = 0;
        int currEnd = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++){
            if(intervals[i][0] < currEnd && intervals[i][1] < currEnd){
                ans++;
                currEnd = intervals[i][1];
            }else if(intervals[i][0] < currEnd){
                ans++;
            }else{
                currEnd = intervals[i][1];
            }
        }
        return ans;
    }
};

int main(){
    Solution obj;
    vector<vector<int>> intervals = {{1,2},{2,3},{3,4},{1,3}};
    cout << obj.eraseOverlapIntervals(intervals) << endl;
}