#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<map>
#include<set>
#include<string>
#include<algorithm>

#include "utils.h"

using namespace std;

class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<vector<int>> horizontal;
        vector<vector<int>> verticle;
        for(auto& rect : rectangles){
            horizontal.push_back({rect[0], rect[2]});
            verticle.push_back({rect[1], rect[3]});
        }

        sort(horizontal.begin(), horizontal.end());
        sort(verticle.begin(), verticle.end());

        // Horizontal direction check.
        int cuts = 0;
        int currEnd = horizontal[0][1];
        for(auto& segment : horizontal){
            if(segment[0] >= currEnd){
                cuts++;
                if(cuts > 1){
                    return true;
                }
            }
            currEnd = max(currEnd, segment[1]);
        }

        cuts = 0;
        currEnd = verticle[0][1];
        for(auto& segment: verticle){
            if(segment[0] >= currEnd){
                cuts++;
                if(cuts > 1){
                    return true;
                }
            }
            currEnd = max(currEnd, segment[1]);
        }
        cout << "Cuts: " << cuts << endl;
        return false;
    }
};

int main(){
    Solution solution;
    vector<vector<int>> input = {{1,0,5,2},{0,2,2,4},{3,2,5,3},{0,4,4,5}};
    bool answer = solution.checkValidCuts(5, input);
    cout << "Answer: " << answer << endl;
}