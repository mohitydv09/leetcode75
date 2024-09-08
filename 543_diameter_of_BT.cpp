#include<iostream>
#include<vector>
#include<queue>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    // Constructors
    TreeNode() : val(0), left(nullptr), right(nullptr) {};
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {};
};

class Solution {
public:
    int maxDia = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        int depth = maxDepth(root);
        return maxDia;
    }

    int maxDepth(TreeNode* root){
        if(!root){return 0;}
        int depthLeft = maxDepth(root->left);
        int depthRight = maxDepth(root->right);
        int dia = depthLeft + depthRight + 2;
        if (dia > maxDia){
            maxDia = dia;
        }
        return std::max(depthLeft, depthRight) + 1;
    }
};

int main() {
    std::vector<int> input = {4,2,7,1,3,6,9};
    // Create Tree from Input.
    TreeNode* root = new TreeNode(input[0]);
    std::queue<TreeNode*> q;
    q.push(root);

    for (int i = 1; i < input.size(); ++i){
        TreeNode* current = q.front();
        TreeNode* newNode = new TreeNode(input[i]);
        if(!current->left){
            current->left = newNode;
        }else if(!current->right){
            current->right = newNode;
            q.pop();
        }
        q.push(newNode);
    }

    Solution solution;
    int answer = solution.diameterOfBinaryTree(root);
    std::cout << "Answer: " << answer << std::endl;
};