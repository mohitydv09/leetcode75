#include<iostream>
#include<vector>
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
    std::vector<std::vector<int>> levelOrder(TreeNode* root) {
        if(!root){return {};};

        std::queue<TreeNode*> frontier;
        frontier.push(root);

        std::vector<std::vector<int>> answer;

        while(!frontier.empty()){
            int qLength = frontier.size();
            std::vector<int> level(qLength);
            for (int i = 0; i < qLength; ++i){
                TreeNode* current = frontier.front(); frontier.pop();
                if(current->left){frontier.push(current->left);};
                if(current->right){frontier.push(current->right);};
                level[i] = current->val;
            }
            answer.push_back(level);
        }
        return answer;
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
    std::vector<std::vector<int>> answer = solution.levelOrder(root);
    for (auto item : answer){
        std::cout << "Item " << std::endl;
        for (int value : item){
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }
};