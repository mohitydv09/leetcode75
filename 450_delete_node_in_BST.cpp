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
    TreeNode* deleteNode(TreeNode* root, int key) {
        // Corner Case handeling.
        if(!root){
            return root;
        }

        TreeNode* prev_node = nullptr;
        TreeNode* curr_node = root;
        bool leftChild = false;

        while(curr_node){
            if (key == curr_node->val ){
                TreeNode* rightSubtree = curr_node->right;
                TreeNode* leftSubtree = curr_node->left;
                // If parent exists.
                if(prev_node){
                    if (rightSubtree && leftSubtree){
                        // Both the sub trees exists.
                        TreeNode* leftmostNode = rightSubtree;
                        while(leftmostNode->left){
                            leftmostNode = leftmostNode->left;
                        }
                        // Replace Nodes.
                        if (leftChild){
                            prev_node->left = rightSubtree;
                            leftmostNode->left = leftSubtree;
                        }else{
                            prev_node->right = rightSubtree;
                            leftmostNode->left = leftSubtree;
                        }

                    }else if(rightSubtree && !leftSubtree){
                        if (leftChild){
                            prev_node->left = rightSubtree;
                        }else{
                            prev_node->right = rightSubtree;
                        }
                    }else if(!rightSubtree && leftSubtree){
                        if (leftChild){
                            prev_node->left = leftSubtree;
                        }else{
                            prev_node->right = leftSubtree;
                        }
                    }else{
                        if (leftChild){
                            prev_node->left = nullptr;
                        }else{
                            prev_node->right = nullptr;
                        }
                    }
                }else{
                    // Parent Doesn't exist.
                    if (rightSubtree && leftSubtree){
                        // Both the sub trees exists.
                        TreeNode* leftmostNode = rightSubtree;
                        while(leftmostNode->left){
                            leftmostNode = leftmostNode->left;
                        }
                        // Replace Nodes.
                        root = rightSubtree;
                        leftmostNode->left = leftSubtree;
                    }else if(rightSubtree && !leftSubtree){
                        root = rightSubtree;
                    }else if(!rightSubtree && leftSubtree){
                        root = leftSubtree;
                    }else{
                        root = nullptr;
                    }
                }
                break;
            }else if (key < curr_node->val){
                prev_node = curr_node;
                leftChild = true;
                curr_node = curr_node->left;
            }else {
                prev_node = curr_node;
                leftChild = false;
                curr_node = curr_node->right;
            }
        }
        return root; 
    }
};


int main(){
    Solution solution_instance;
    vector<int> input_head = {2,1,3};

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

    cout << "Return node val : " << solution_instance.deleteNode(head, 1)->right->val << endl;
    return 0;
}