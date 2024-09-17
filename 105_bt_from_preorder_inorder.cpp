#include<iostream>
#include<vector>
#include<algorithm>


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {};
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {};
};

#include <vector>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder) {
        return buildNode(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }

private:
    TreeNode* buildNode(const std::vector<int>& preorder, int preStart, int preEnd,
                        const std::vector<int>& inorder, int inStart, int inEnd) {
        if (preStart > preEnd || inStart > inEnd) {
            return nullptr;
        }

        TreeNode* newNode = new TreeNode(preorder[preStart]);
        
        // Find the index of the root in the inorder traversal
        int rootInorderIndex = inStart;
        while (rootInorderIndex <= inEnd && inorder[rootInorderIndex] != preorder[preStart]) {
            rootInorderIndex++;
        }

        // Number of nodes in the left subtree
        int leftSize = rootInorderIndex - inStart;

        // Recursively build the left and right subtrees
        newNode->left = buildNode(preorder, preStart + 1, preStart + leftSize, inorder, inStart, rootInorderIndex - 1);
        newNode->right = buildNode(preorder, preStart + leftSize + 1, preEnd, inorder, rootInorderIndex + 1, inEnd);

        return newNode;
    }
};


int main(){
    std::vector<int> preorder = {1,2};
    std::vector<int> inorder = {2,1};

    Solution solution;
    TreeNode* root = solution.buildTree(preorder, inorder);
    std::cout << "Answer Root: " << root->val << std::endl;
}