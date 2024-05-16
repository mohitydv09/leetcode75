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

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int longestZigZag(TreeNode* root){
        if (!root){
            return 0;
        }
        return max(countZigZag(root->left, true, 0), countZigZag(root->right, false, 0));
    };

private:
    int countZigZag(TreeNode* root, bool isLeft, int depth){
        if (root == nullptr){
            return depth;
        }
        if (isLeft){
            return max( countZigZag(root->right, false, depth+1),
                        countZigZag(root->left, true, 0));
        }else{
            return max( countZigZag(root->left, true, depth+1),
                        countZigZag(root->right, false, 0));
        }
    };
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
    cout << solution_instance.longestZigZag(head) << endl;
    return 0;
} 