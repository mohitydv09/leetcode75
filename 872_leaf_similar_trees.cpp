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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        // To find the leaf sequence.
        // Do DFS on both the trees.
        vector<int> tree_leafs1;
        vector<int> tree_leafs2;

        stack<TreeNode*> tree_stack1; // WE add a star here as the stack will have pointers and not values.
        tree_stack1.push(root1);
        while(!tree_stack1.empty()){
            // Do something.
            // Remove the item from stack.
            TreeNode *current_node = tree_stack1.top();
            tree_stack1.pop();
            cout << "Current Node which is being explored : " << current_node->val << endl;
            if(current_node->right){
                tree_stack1.push(current_node->right);
            }
            if(current_node->left){
                tree_stack1.push(current_node->left);
            }
            if(!current_node->right && !current_node->left){
                tree_leafs1.push_back(current_node->val);
            }
        }

        stack<TreeNode*> tree_stack2; // WE add a star here as the stack will have pointers and not values.
        tree_stack2.push(root2);
        while(!tree_stack2.empty()){
            // Do something.
            // Remove the item from stack.
            TreeNode *current_node = tree_stack2.top();
            tree_stack2.pop();
            cout << "Current Node which is being explored : " << current_node->val << endl;
            if(current_node->right){
                tree_stack2.push(current_node->right);
            }
            if(current_node->left){
                tree_stack2.push(current_node->left);
            }
            if(!current_node->right && !current_node->left){
                tree_leafs2.push_back(current_node->val);
            }
        }


        cout << "Tree leafs are : ";
        for(int item : tree_leafs2){
            cout << item;
        }
        cout << endl;
        return (tree_leafs1==tree_leafs2);
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

    cout << "This is trial print : " << head->left->right->val << endl;
    cout << solution_instance.leafSimilar(head, head) << endl;
    return 0;
} 