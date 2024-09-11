#include<iostream>
#include<queue>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    // Constructors
    TreeNode() : val(0), left(nullptr), right(nullptr) {};
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {};
};

class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root){return false;}
        std::queue<TreeNode*> frontier;
        frontier.push(root);
        while(!frontier.empty()){
            TreeNode* current = frontier.front(); frontier.pop();
            bool isSub = isSameTree(current, subRoot);
            if(isSub){return true;}
            if(current->left){frontier.push(current->left);}
            if(current->right){frontier.push(current->right);}
        }
        return false;
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q){return true;}
        if((!p && q) || (p && !q)){return false;}
        
        std::queue<TreeNode*> pFrontier;
        std::queue<TreeNode*> qFrontier;
        pFrontier.push(p);
        qFrontier.push(q);
        while(!pFrontier.empty() || !qFrontier.empty()){
            TreeNode* pCurrent = pFrontier.front(); pFrontier.pop();
            TreeNode* qCurrent = qFrontier.front(); qFrontier.pop();
            if(pCurrent->val != qCurrent->val){
                return false;
            }
            if((pCurrent->left && !qCurrent->left) || (!pCurrent->left && qCurrent->left)){
                return false;
            }
            if((pCurrent->right && !qCurrent->right) || (!pCurrent->right && qCurrent->right)){
                return false;
            }
            if(pCurrent->left){pFrontier.push(pCurrent->left);};
            if(pCurrent->right){pFrontier.push(pCurrent->right);};
            if(qCurrent->left){qFrontier.push(qCurrent->left);};
            if(qCurrent->right){qFrontier.push(qCurrent->right);};
        }
        return true;
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
    bool answer = solution.isSameTree(root, root);
    std::cout << "Answer: " << answer << std::endl;
};