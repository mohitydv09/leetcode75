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
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* curr_node = root;
        TreeNode* req_node = nullptr;

        while(curr_node != nullptr){
            if (val == curr_node->val ){
                req_node = curr_node;
                break;
            }else if (val < curr_node->val){
                curr_node = curr_node->left;
            }else {
                curr_node = curr_node->right;
            }
        }
        return req_node; 
    }
};


int main(){
    Solution solution_instance;
    vector<int> input_head = {4,2,5,1,3};

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

    cout << "This is trial print : " << head->left->val << endl;
    cout << "Return node val : " << solution_instance.searchBST(head, 10)->val << endl;
    return 0;
} 