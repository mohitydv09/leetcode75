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
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        int currStart = meetings[0][0];
        int currEnd = meetings[0][1];

        int count = currStart - 1;

        for(auto& meeting : meetings){
            if(meeting[0] > currEnd){
                //Gap found
                count += meeting[0] - currEnd - 1;
            }
            currEnd = max(currEnd, meeting[1]);
        }
        count += days - currEnd;
        return count;
    }
};

int main(){
    Solution solution;
    vector<vector<int>> input = {{5,7}, {1,3}, {9,10}};
    int answer = solution.countDays(10, input);
    cout << "Answer: " << answer << endl;
}