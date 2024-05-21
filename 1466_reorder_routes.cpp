#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        stack<int> frontier;
        vector<bool> visited(n, false);
        int change_counter = 0;
        // vector<bool> visited_connection(connections.size(), false);

        vector<vector<int>> city_connection(n, vector<int>());
        for(int i = 0; i < connections.size(); i++){
            city_connection[connections[i][0]].push_back(i);
            city_connection[connections[i][1]].push_back(i);
        }

        frontier.push(0);
        while(!frontier.empty()){
            int curr_city = frontier.top();
            visited[curr_city] = true;
            frontier.pop();
            for (int idx : city_connection[curr_city]){
                if (connections[idx][1] == curr_city && !visited[connections[idx][0]]){ 
                        frontier.push(connections[idx][0]);
                    }else if(connections[idx][0] == curr_city && !visited[connections[idx][1]]){
                        change_counter++;
                        frontier.push(connections[idx][1]);
                    }
                }
            }
        return change_counter;
    }
};

int main(){
    Solution solution_instance;
    vector<vector<int>> input = {{0,1},{1,3},{2,3},{4,0},{4,5}};
    cout << "Answer : " << solution_instance.minReorder(6,input) << endl;
    return 0;
}