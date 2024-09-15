#include <iostream>
#include <vector>
#include <queue>
#include <stack>

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
    int kthSmallest(TreeNode* root, int k) {
        std::stack<TreeNode*> st;
        TreeNode* iter = root;
        int counter = 0;
        while(true){
            while(iter){
                st.push(iter);
                iter = iter->left;
            }
            iter = st.top(); st.pop();
            counter++;
            if (counter == k){
                return iter->val;
            }
            iter = iter->right;
        } 
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
    int answer = solution.kthSmallest(root, 3);
    std::cout << "Answer: " << answer << std::endl;
};