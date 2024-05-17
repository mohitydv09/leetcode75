#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return dfs( root, p, q);
    }

private:
    TreeNode* dfs(TreeNode* root, TreeNode *p,  TreeNode* q){
        // If the root is null return null
        if (root == nullptr){
            return nullptr;
        }
        // If root is one of p or q then return that node.
        if (root->val == p->val || root->val == q->val){
            return root;
        }

        // Call the childs recursively
        TreeNode* left = dfs(root->left, p, q);
        TreeNode* right = dfs(root->right, p, q);

        // If both of the childs return some value that this is the common ancestor.
        if (left != nullptr && right != nullptr ){
            return root;
        // if only one of them return a value, we just return that value to the parent call.
        }else if(left != nullptr && right == nullptr){
            return left;
        }else{
            return right;
        }
        }
};


int main(){
    Solution solution_instance;
    vector<int> input_head = {1,2,3,4,5};

    TreeNode *head = new TreeNode(input_head[0]);
    queue<TreeNode*> frontier;
    frontier.push(head);

    for (int i = 1; i < input_head.size(); i++){
        TreeNode *temp_node = new TreeNode(input_head[i]);
        if(i%2 != 0){
        // put on left side.
            frontier.front()->left = temp_node;
            frontier.push(temp_node);
        }else{
            frontier.front()->right = temp_node;
            frontier.push(temp_node);
            frontier.pop();
        }
    }
    TreeNode *p = head->left->left;
    TreeNode *q = head->left->right;

    cout << "This is trial print : " << head->left->right->val << endl;
    cout << solution_instance.lowestCommonAncestor(head, p , q)->val << endl;
    return 0;
} 