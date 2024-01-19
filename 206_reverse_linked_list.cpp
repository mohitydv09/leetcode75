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
        ListNode *reverse_ll = nullptr;
        ListNode *current_node = head;
        while(current_node){
            ListNode *temp_pointer = current_node->next;
            current_node->next = reverse_ll;
            reverse_ll = current_node;
            current_node = temp_pointer;
        }
        cout << "reverse funtion ram" << endl;
        return reverse_ll;
    }
};

int main(){
    Solution solution_instance;
    vector<int> input_head = {1,2,3,4,5};

    ListNode *head = new ListNode();
    ListNode *current_node = head;

    for (int i = 0; i < input_head.size()-1; i++){
        ListNode *temp_node = new ListNode();
        current_node->val = input_head[i];
        current_node->next = temp_node;
        current_node = current_node->next;
    }
    current_node->val = input_head[input_head.size()-1];

    ListNode *solution = solution_instance.reverseList(head);
    while(solution){
        cout << "This is solution item : " << solution->val << endl;
        solution = solution->next;
    }
    return 0;
} 