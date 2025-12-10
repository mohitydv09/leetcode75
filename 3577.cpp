#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        for(int i = 1; i < complexity.size(); ++i){
            if (complexity[i] <= complexity[0]){
                return 0;
            }
        }
        int n = complexity.size()-1;
        unsigned long factorial = 1;
        unsigned long MOD = 1000000007;
        for (int i = n; i > 0; --i){
            factorial *= i;
            factorial %= MOD;
        }
        return factorial;
    }
};

int main(){
    Solution solution;
    vector<int> complexity = {1, 2, 3};
    int answer = solution.countPermutations(complexity);
    std::cout << "Answer: " << answer << std::endl;
}