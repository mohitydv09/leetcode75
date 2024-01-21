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
    int goodNodes(TreeNode* root) {
        return dfs(root, root->val);
    }

private:
    int dfs(TreeNode* root, int max_value){
        if(!root){
            return 0;
        }
        cout << "DFS recieved : " << root->val << endl;
        cout << "DFS Max Value: " << max_value << endl;
        int count = 0;
        if(root->val >= max_value){
            max_value = root->val;
            count++;
        }
        count += dfs(root->left, max_value);
        count += dfs(root->right, max_value);
        cout << "Current Count is : " << count << endl;
        return count;
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
    cout << solution_instance.goodNodes(head) << endl;
    return 0;
} 