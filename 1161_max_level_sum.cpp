#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <limits>
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
    int maxLevelSum(TreeNode* root) {
        int max_level = 1;
        int max_sum = root->val;

        queue<TreeNode*> frontier;
        frontier.push(root);

        int curr_level = 0;
        while(!frontier.empty()){
            int curr_frontier_len = frontier.size();
            curr_level ++;
            int curr_sum = 0;
            for (int i = 0; i < curr_frontier_len ; i++){
                TreeNode* curr_node = frontier.front();
                frontier.pop();
                curr_sum += curr_node->val;
                if (curr_node->left != nullptr){
                    frontier.push(curr_node->left);
                }
                if (curr_node->right != nullptr){
                    frontier.push(curr_node->right);
                }
            }
            if (curr_sum > max_sum){
                max_sum = curr_sum;
                max_level = curr_level;
            }
        }
        return max_level;
    }
};


int main(){
    Solution solution_instance;
    vector<int> input_head = {1,2,3};

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
    cout << "Ans : " << solution_instance.maxLevelSum(head) << endl;
    return 0;
} 