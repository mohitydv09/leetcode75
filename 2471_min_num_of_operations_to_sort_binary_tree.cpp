#include<iostream>
#include<vector>
#include<queue>
#include<optional>
#include<algorithm>
#include "utils.h"


using namespace std;

class Solution {
public:
    int minimumOperations(TreeNode* root) {
        int ans = 0;

        queue<TreeNode*> frontier;
        frontier.push(root);

        while(!frontier.empty()){
            int currSize = frontier.size();
            vector<int> levelValues(currSize);
            for (int i = 0; i < currSize; ++i){
                TreeNode* current = frontier.front(); frontier.pop();
                levelValues[i] = current->val;
                if(current->left != nullptr){frontier.push(current->left);};
                if(current->right != nullptr){frontier.push(current->right);};
            }
            ans += minSwaps(levelValues);
        }
        return ans;
    }

private:
    int minSwaps(vector<int>& values){
        int swaps = 0;
        vector<int> sortedValues = values;
        sort(sortedValues.begin(), sortedValues.end());
        unordered_map<int, int> sortedMap; // item -> idx
        for(int i = 0; i < sortedValues.size(); ++i){
            sortedMap[sortedValues[i]] = i;
        }
        for(int i = 0; i < values.size(); ++i){
            while(!(sortedMap[values[i]] == i)){
                //swap
                int temp = values[sortedMap[values[i]]];
                values[sortedMap[values[i]]] = values[i];
                values[i] = temp;
                swaps++;
            }
        }
        return swaps;
    }
};

int main(){
    Solution solution;
    vector<optional<int>> inputTree = {1,4,3,7,6,8,5,nullopt,nullopt,nullopt,nullopt,9,nullopt,10};
    TreeNode* root = vector2BinaryTree(inputTree);
    int answer = solution.minimumOperations(root);
    cout << "Answer: " << answer << endl;
    delete root;
}   