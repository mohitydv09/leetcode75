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
    int count = 0;
    int goodNodes(TreeNode* root) {
        dfs(root, root->val);
        return count;
    }

private:
    void dfs(TreeNode* root, int max_value){
        if(!root){return;}

        if(root->val >= max_value){
            max_value = root->val;
            count++;
        }
        if(root->left){dfs(root->left, max_value);}
        if(root->right){dfs(root->right, max_value);}
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
    int answer = solution.goodNodes(root);
    std::cout << "Answer: " << answer << std::endl;
};