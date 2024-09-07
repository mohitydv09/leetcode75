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
    TreeNode* invertTree(TreeNode* root) {
        if(!root){return root;};
        std::queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* current = q.front();
            q.pop();
            TreeNode* temp = current->left;
            current->left = current->right;
            current->right = temp;

            if(current->left){
                q.push(current->left);
            }
            if(current->right){
                q.push(current->right);
            }
        }
        return root;
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
    TreeNode* answer = solution.invertTree(root);
    std::queue<TreeNode*> qq;
    qq.push(answer);
    std::cout << "Answer: ";
    while(!qq.empty()){
        if(qq.front()->left){
            qq.push(qq.front()->left);
        }
        if(qq.front()->right){
            qq.push(qq.front()->right);
        }
        std::cout << qq.front()->val << " ";
        qq.pop();
    }
    std::cout << std::endl;
};