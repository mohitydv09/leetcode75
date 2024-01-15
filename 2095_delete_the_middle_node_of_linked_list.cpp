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
    ListNode* deleteMiddle(ListNode* head) {
        // We need to find the size of ll first.
        ListNode *current_node = head;
        int n = 1;
        while(!(current_node->next == nullptr)){
            cout << "Current Node is : " << (*current_node).val << endl;
            current_node = (*current_node).next;
            n++;
        }
        // For edge case of only one item.
        if(n ==1){
            return nullptr;
        }

        // Middle element.
        int mid = n/2;
        cout << "Mid index is : " << mid << endl;

        //  Go to mid-1 index.
        ListNode *before_mid_pointer = head;
        for (int i = 0; i < mid-1; i++){
            before_mid_pointer = (*before_mid_pointer).next;
        }
        cout  << "Mid Pointer Value : " << (*before_mid_pointer).val << endl;
        ListNode *mid_value = before_mid_pointer->next;
        ListNode *next_element = mid_value->next;
        before_mid_pointer->next = next_element;

        return head;
    }
};

int main(){
    Solution solution_instance;
    vector<int> input_head = {1,3,4,7,1,2,6};

    ListNode *head = new ListNode(input_head[0]);
    ListNode *current_node = head;

    for (int i = 1; i < input_head.size(); i++){
        ListNode *next_node = new ListNode(input_head[i]);
        (*current_node).next = next_node;
        current_node = (*current_node).next;
        cout << "Current Node updated : " << (*current_node).val << endl;
    }

    cout << (*head).val << endl;
    solution_instance.deleteMiddle(head);
    return 0;
} 