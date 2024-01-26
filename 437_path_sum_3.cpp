#include <iostream>
#include <vector>
#include <stack>
#include <map>
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
    int pathSum(TreeNode* root, int targetSum) {
        if(!root){return 0;}
        map<long long, int> sums;
        sums[0] = 1;
        int count = counter(root, targetSum, sums);

        // Below is just for printing the map after it has been created.
        map<long long, int>::iterator it;
        for(it = sums.begin(); it != sums.end(); it++){
            cout << "Key is : " << it-> first <<  " , Value is : " << it->second << endl;
        }
        return count;
    }

public:
    int counter(TreeNode* root, int targetSum, map<long long, int> &sums, long long prev_sum = 0){
        if(!root){return 0;}
        cout << "Counter ran for : " << root->val << ". Prev Sum is : " << prev_sum << endl;
        prev_sum += root->val;
        int count = sums[prev_sum-targetSum];
        sums[prev_sum]++;
        count += counter(root->left, targetSum, sums, prev_sum);
        count += counter(root->right, targetSum, sums, prev_sum);
        sums[prev_sum]--;
        return count;
    }
};

int main(){
    Solution solution_instance;
    vector<int> input_head = {1};

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
    cout << solution_instance.pathSum(head,0) << endl;
    return 0;
} 