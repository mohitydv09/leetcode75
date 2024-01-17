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
    ListNode* oddEvenList(ListNode* head) {
        // We need to find the size of ll first.
        if(!head){
            return head;
        }
        if((*head).next == nullptr){
            // If the passed ll is of size one.
            return head;
        }
        if(head->next->next == nullptr){
            return head;
        }


        ListNode *current_node = head;
        int n = 1;
        // Find the size of the ll and also the pointer to its tail.
        while(current_node->next){
            n++;
            current_node = current_node->next;
        }
        ListNode *tail_node = current_node;
        current_node = head;
        cout << "Size of LL : " << n << endl;
        cout << "Tail Pointer Value : " << tail_node->val << endl;
        cout << "Head Pointer Value : " << current_node->val << endl;
        n = n/2;
        for(int i = 1; i <= n; i++ ){
            // Odd Case, here we have to change the next item.
            // Make a new node.
            ListNode *new_node = new ListNode(current_node->next->val);
            current_node->next = current_node->next->next;
            tail_node->next = new_node;
            tail_node = new_node;
            current_node = current_node->next;
        }
        return head;
    }
};

int main(){
    Solution solution_instance;
    vector<int> input_head = {2,1,3,5};

    ListNode *head = new ListNode(input_head[0]);
    ListNode *current_node = head;

    for (int i = 1; i < input_head.size(); i++){
        ListNode *next_node = new ListNode(input_head[i]);
        (*current_node).next = next_node;
        current_node = (*current_node).next;
        cout << "Current Node updated : " << (*current_node).val << endl;
    }

    cout << (*head).val << endl;
    ListNode *solution = solution_instance.oddEvenList(head);
    while(solution->next){
        cout << "This is solution item : " << solution->val << endl;
        solution = solution->next;
    }
    cout << "This is solution item : " << solution->val << endl;
    return 0;
} 