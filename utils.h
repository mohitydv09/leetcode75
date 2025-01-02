// Auxilary funtions need in code.

// Check if utils in defined earlier or not,
// helps remove mulitple inclusions.
#pragma once

#include<iostream>
#include<vector>
#include<optional>
#include<queue>


using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode * right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {};
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {};
};

TreeNode* vector2BinaryTree(const vector<optional<int>>& inputTree){
    if (inputTree.empty() || !inputTree[0].has_value()){
        return nullptr;
    }

    TreeNode* root = new TreeNode(inputTree[0].value());
    queue<TreeNode*> nodeQueue;
    nodeQueue.push(root);

    int idx = 1;
    while(!nodeQueue.empty() && idx < inputTree.size()){
        TreeNode* current = nodeQueue.front(); nodeQueue.pop();

        if(idx < inputTree.size() && inputTree[idx].has_value()){
            current->left = new TreeNode(inputTree[idx].value());
            nodeQueue.push(current->left);
        }
        idx++;
        if(idx < inputTree.size() && inputTree[idx].has_value()){
            current->right = new TreeNode(inputTree[idx].value());
            nodeQueue.push(current->right);
        }
        idx++;
    }
    return root;
}

void deleteTree(TreeNode* root){
    if(!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

template <typename T>
void printVector(vector<T>& vec){
    for(const auto& ele : vec){
        cout << ele << " ";
    }
    cout << endl;
}