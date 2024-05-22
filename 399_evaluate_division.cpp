#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <set>
#include <tuple>

using namespace std;

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        set<string> variables;
        for (int i = 0; i < equations.size(); i++){
            variables.insert(equations[i][0]);
            variables.insert(equations[i][1]);
        }

        // Insert the reverse nodes and values.
        int N = equations.size();
        for (int i = 0; i < N; i++){
            equations.push_back({equations[i][1], equations[i][0]});
            values.push_back(1/values[i]);
        }

        unordered_map<string, int> var2int;
        unordered_map<int, string> int2var;
        int iter = 0;
        for (string item : variables){
            var2int[item] = iter;
            int2var[iter] = item;
            iter++;
        }

        // Build the adjacency matrix.
        vector<vector<tuple<double, int>>> adj_mat(variables.size());
        for(int i = 0; i < equations.size(); i++){
            adj_mat[var2int[equations[i][0]]].push_back(make_tuple(values[i],var2int[equations[i][1]]));
        }

        vector<double> solution(queries.size(),-1);
        // For each query we do a dfs.
        for(int i = 0; i < queries.size(); i++){
            // Check if values exit in the map.
            if(var2int.count(queries[i][0])>0 && var2int.count(queries[i][1])>0){
                if (queries[i][0] == queries[i][1]){
                    solution[i] = 1;
                }else{
                    int from = var2int[queries[i][0]];
                    int to = var2int[queries[i][1]];

                    vector<bool> visited(variables.size(), false);
                    double ans = 1.0;
                    tuple<double, bool> result = dfs(from, to, ans, adj_mat, values, visited, false);
                    if (get<1>(result)){
                        solution[i] = get<0>(result);
                    }
                }
            }
        }
        return solution;
    }
private:
    tuple<double, bool> dfs(int curr_node, int target, double ans, const vector<vector<tuple<double, int>>>& adj_mat, const vector<double>& values, vector<bool>& visited, bool flag){
        // Set the visited true for this node
        visited[curr_node] = true;
        if(curr_node == target){
            tuple<double, bool> result(ans, true);
            return result;
        }else{
            // Run DFS on neighbours of this.
            for (int i = 0; i < adj_mat[curr_node].size(); i++){
                double value = get<0>(adj_mat[curr_node][i]);
                int neigh = get<1>(adj_mat[curr_node][i]);
                if (!visited[neigh]){
                    tuple<double, bool> result = dfs(neigh, target, ans * value , adj_mat, values, visited, false);
                    if(get<1>(result)){
                        return result;
                    }
                }
            }
        }
        tuple<double, bool> result(ans, false);
        return result;
    }
};

int main(){
    Solution solution_instance;
    vector<vector<string>> equations = {{"a","b"}};
    vector<double> values = {2.0, 3.0};
    vector<vector<string>> queries = {{"a","b"},{"b","a"},{"a", "c"},{"a","e"},{"a","a"},{"x","x"}};
    vector<double> ans = solution_instance.calcEquation(equations, values, queries);
    cout << "Answer : " << endl;
    for (double item : ans){
        cout << item << " ";
    }
    cout << endl;
    return 0;
}