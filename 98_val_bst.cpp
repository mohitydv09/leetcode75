#include <iostream>
#include <vector>
#include <queue>

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
    bool isValidBST(TreeNode* root) {
        return dfs(root, LLONG_MAX, LLONG_MIN);
    }
private:
    bool dfs(TreeNode* root, long long maxValue, long long minValue){
        if(!root){return true;}

        if(minValue > root->val || root->val > maxValue) return false;
        
        return dfs(root->left, (double)root->val, minValue) && dfs(root->right, maxValue, (double)root->val);
    }
};

int main() {
    // std::vector<int> input = {4,2,7,1,5,6,9};
    std::vector<int> input = {0,-1};
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
    bool answer = solution.isValidBST(root);
    std::cout << "Answer: " << answer << std::endl;
};