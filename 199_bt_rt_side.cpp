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
    vector<int> rightSideView(TreeNode* root) {

        vector<int> solution;
        if (root == nullptr){
            return solution;
        }
        queue<TreeNode*> frontier;
        frontier.push(root);
        while(!frontier.empty()){
            solution.push_back(frontier.back()->val);
            int curr_frontier_len = frontier.size();
            for (int i = 0; i < curr_frontier_len ; i++){
                TreeNode* curr_node = frontier.front();
                frontier.pop();
                if (curr_node->left != nullptr){
                    frontier.push(curr_node->left);
                }
                if (curr_node->right != nullptr){
                    frontier.push(curr_node->right);
                }
            }
        }
        return solution;
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
    for (int item : solution_instance.rightSideView(head)){
        cout << item; 
    }
    cout << endl;
    return 0;
} 