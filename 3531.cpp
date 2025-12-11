
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        vector<vector<int>> x_limits(n, vector<int> {n, 0});
        vector<vector<int>> y_limits(n, vector<int> {n, 0});

        for (int i = 0; i < buildings.size(); ++i){
            int x = buildings[i][0];
            int y = buildings[i][1];
            
            // Fill x_limits
            x_limits[y-1][0] = min(x_limits[y-1][0], x);
            x_limits[y-1][1] = max(x_limits[y-1][1], x);

            // Fill y_limits
            y_limits[x-1][0] = min(y_limits[x-1][0], y);
            y_limits[x-1][1] = max(y_limits[x-1][1], y);
        }

        for (int i = 0; i < x_limits.size(); ++i){
            cout << "XLIM: " << x_limits[i][0] << x_limits[i][1] << endl;
            cout << "YLIM: " << y_limits[i][0] << y_limits[i][1] << endl;
        }

        int covered_count = 0;
        for (int i = 0; i < buildings.size(); ++i){
            int x = buildings[i][0];
            int y = buildings[i][1];

            if (x > x_limits[y-1][0] &&
                x < x_limits[y-1][1] &&
                y > y_limits[x-1][0] &&
                y < y_limits[x-1][1]){
                    covered_count++;
                }
        }
        return covered_count;
    }
};

int main(){
    Solution solution;
    vector<vector<int>> buildings = {{2,4}, {1, 2}, {3,1 }, {1, 4}, {2, 3}, {3, 3}, {2, 2} , {1, 3}};
    int answer = solution.countCoveredBuildings(4,buildings);
    std::cout << "Answer: " << answer << std::endl;
}