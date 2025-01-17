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
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int> answer;
        for(int i = 0; i < queries.size(); ++i){
            int count = 0;
            for(int j = 0; j < points.size(); ++j){
                int dist = (points[j][0] - queries[i][0])*(points[j][0] - queries[i][0]) + (points[j][1] - queries[i][1])*(points[j][1] - queries[i][1]);
                if(dist <= queries[i][2]*queries[i][2]){
                    count++;
                }
            }
            answer.push_back(count);
        }
        return answer;
    }
};

int main(){
    Solution solution;
    vector<vector<int>> points = {{1,3}, {2,2}, {3,3}, {5,3}};
    vector<vector<int>> queries = {{2,3,1}, {4,3,1}, {1,1,2}};
    vector<int> answer = solution.countPoints(points, queries);
    cout << "Answer: " << endl;
    printVector(answer);
}