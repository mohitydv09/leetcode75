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
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next){return head;}
        ListNode *reverse_ll = new ListNode(head->val);
        ListNode *current_node = head->next;
        while(current_node->next){
            // Add this to end of the other list.
            ListNode *temp_pointer = current_node->next;
            current_node->next = reverse_ll;
            reverse_ll = current_node;
            current_node = temp_pointer;
        }
        current_node->next = reverse_ll;
        return current_node;
    }
};

int main(){
    Solution solution_instance;
    vector<int> input_head = {1,2,3,4,5};

    ListNode *head = new ListNode(input_head[0]);
    ListNode *current_node = head;

    for (int i = 1; i < input_head.size(); i++){
        ListNode *next_node = new ListNode(input_head[i]);
        (*current_node).next = next_node;
        current_node = (*current_node).next;
        cout << "Current Node updated : " << (*current_node).val << endl;
    }

    cout << (*head).val << endl;
    ListNode *solution = solution_instance.reverseList(head);
    while(solution->next){
        cout << "This is solution item : " << solution->val << endl;
        solution = solution->next;
    }
    cout << "This is solution item : " << solution->val << endl;
    return 0;
} 