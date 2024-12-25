#include<iostream>
#include<vector>
#include<queue>
#include<optional>
#include<climits>
#include<unordered_map>
#include "utils.h"

using namespace std;

class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        if (!root){return {};};
        
        vector<int> answer;
        queue<TreeNode*> frontier;
        frontier.push(root);

        while(!frontier.empty()){
            int levelMax = INT_MIN;
            int currSize = frontier.size();
            for(int i = 0; i < currSize; ++i){
                TreeNode* currentNode = frontier.front(); frontier.pop();

                levelMax = max(levelMax, currentNode->val);

                if(currentNode->left){frontier.push(currentNode->left);};
                if(currentNode->right){frontier.push(currentNode->right);};
            }
            answer.push_back(levelMax);
        }
        return answer;
    }
};

int main(){
    Solution solution;
    vector<optional<int>> inputVector = {1,3,2,5,3,nullopt,9};
    TreeNode* root = vector2BinaryTree(inputVector);
    vector<int> answer = solution.largestValues(root);
    cout << "Answer: ";
    for(const auto& item : answer){
        cout << item << " ";
    }
    cout << endl;
}