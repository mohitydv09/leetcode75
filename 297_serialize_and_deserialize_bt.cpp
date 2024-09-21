#include<iostream>
#include<string>
#include<sstream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:
    // Encodes a tree to a single string.
    std::string serialize(TreeNode* root) {
        // Save the preorder tranversal
        std::string serializedTree;
        preOrder(root, serializedTree);
        return serializedTree;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(std::string data) {
        std::stringstream ss(data);
        std::string token;
        std::vector<std::string> treeItems;
        while(ss >> token){
            treeItems.push_back(token);
        }
        int i = 0;
        return dfs(treeItems);
    }

private:
    int i = 0;
    void preOrder(TreeNode* root, std::string &serializedTree){
        if(!root){
            serializedTree.append("NULL ");
            return;
        };
        serializedTree.append(std::to_string(root->val) + " ");
        preOrder(root->left, serializedTree);
        preOrder(root->right, serializedTree);
        return;
    }

    TreeNode* dfs(std::vector<std::string>& treeItems){
        if(i >= treeItems.size()){return nullptr;};
        if(treeItems[i] == "NULL"){
            i++;
            return nullptr;
        }
        TreeNode* newNode = new TreeNode(std::stoi(treeItems[i]));
        i++;
        newNode->left = dfs(treeItems);
        newNode->right = dfs(treeItems);
        return newNode;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

int main(){
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

    Codec ser, deser;
    // TreeNode* ans = deser.deserialize(ser.serialize(root));
    std::cout << "Serialized Tree: " << ser.serialize(root) << std::endl;
    TreeNode* tempp = ser.deserialize(ser.serialize(root));
    std::cout << "Deserial output: " << ser.deserialize(ser.serialize(root)) << std::endl;
}