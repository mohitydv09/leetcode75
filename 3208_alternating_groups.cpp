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
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        for(int i = 0; i < k-1; ++i){
            colors.push_back(colors[i]);
        }

        int answer = 0;
        int left = 0;
        int right = 1;
        while(right < colors.size()){
            if(colors[right] == colors[right-1]){
                left = right;
                right++;
                continue;
            }
            right++;
            if(right - left < k) continue;
            answer++;
            left++;
        }
        return answer;
    }
};

int main(){
    Solution solution;
    vector<int> input = {0,1,0,1,0};
    int answer = solution.numberOfAlternatingGroups(input, 3);
    cout << "Answer: " << answer << endl;
}