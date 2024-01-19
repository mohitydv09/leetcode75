#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    int pairSum(ListNode* head) {
        int size = 0;
        ListNode *current_node = head;
        while(current_node){
            // cout << "New check : " << current_node->val << endl;
            size++;
            current_node = current_node->next;
        }
        cout << "Size is : " << size << endl;

        ListNode *front_iter = head;
        ListNode *reversed_ll = reverseList(head);

        int max_sum = 0;

        for(int i = 0; i < size/2; i++ ){
            // Get first Item.
            int sum = front_iter->val + reversed_ll->val;
            if (sum > max_sum){
                max_sum = sum;
            }
            reversed_ll = reversed_ll->next;
            front_iter = front_iter->next;
        }
        return max_sum;
    }

    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next){return head;}
        ListNode *reverse_ll = nullptr;
        ListNode *current_node = head;
        while(current_node){
            ListNode *new_node = new ListNode(current_node->val);
            new_node->next = reverse_ll;
            reverse_ll = new_node;
            current_node = current_node->next;
        }
        return reverse_ll;
    }
};

int main(){
    Solution solution_instance;
    vector<int> input_head = {47,22,81,46,94,95,90,22,55,91,6,83,49,65,10,32,41,26,83,99,14,85,42,99,89,69,30,92,32,74,9,81,5,9};

    ListNode *head = new ListNode(input_head[0]);
    ListNode *current_node = head;

    for (int i = 1; i < input_head.size(); i++){
        ListNode *next_node = new ListNode(input_head[i]);
        (*current_node).next = next_node;
        current_node = (*current_node).next;
    }

    cout << solution_instance.pairSum(head) << endl;

    return 0;
} 