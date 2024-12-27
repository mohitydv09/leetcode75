#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int maxScore = 0;
        int maxLeftScore = values[0] + 0;
        for(int i = 1; i < values.size(); ++i){
            int rightScore = values[i] - i;
            maxScore = max(maxScore, maxLeftScore + rightScore);
            maxLeftScore = max(maxLeftScore, values[i] + i);
        }
        return maxScore;
    }
};

int main(){
    Solution solution;
    vector<int> values = {8,1,5,2,6};
    int answer = solution.maxScoreSightseeingPair(values);
    cout << "Answer: " << answer << endl;
}