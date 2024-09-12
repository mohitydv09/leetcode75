#include<iostream>
#include<queue>
#include<unordered_map>

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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* small = (p->val < q->val) ? p : q;
        TreeNode* large = (p->val < q->val) ? q : p;
        while(true){
            if(root->val == small->val || root->val == large->val){return root;}
            if(root->val > small->val && root->val < large->val){return root;}
            if(root->val > small->val){
                root = root->left;
            }else{
                root = root->right;
            }
        }
    }
};

int main() {
    std::vector<int> input = {6,2,8,0,4,7,9};
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
    TreeNode* answer = solution.lowestCommonAncestor(root, root->left, root->right);
    std::cout << "Answer: " << answer->val << std::endl;
};