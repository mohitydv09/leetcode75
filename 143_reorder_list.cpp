#include <iostream>
#include <vector>

struct ListNode{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    // void reorderList(ListNode* head) {
    ListNode* reorderList(ListNode* head) {
        if(!head || !head->next){return head;};
        // Find the second half of the ll.
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast->next){
            slow = slow->next;
            if(!fast->next || !fast->next->next){
                break;
            }else{
                fast = fast->next->next;
            }
        }
        ListNode* back = slow->next;
        slow->next = nullptr;

        // Reverse the back ll.
        ListNode* reversedBack = nullptr;
        while(back){
            ListNode* temp = back;
            back = back->next;
            temp->next = reversedBack;
            reversedBack = temp;
        }

        // Merget the two lls.
        ListNode* mergedLL = head;
        while(head && reversedBack){
            ListNode* temp = reversedBack;
            reversedBack = reversedBack->next;
            temp->next = head->next;
            head->next = temp;
            if(head->next->next){
                head = head->next->next;
            }else{
                break;
            }
        }
        return mergedLL;
    }
};

int main(){
    Solution solution;
    std::vector<int> input = {1,2,3,4,5,6,7};

    ListNode* head = new ListNode(input.back());
    for (int i = input.size()-2; i >= 0; --i){
        head = new ListNode(input[i], head);
    }
    
    ListNode* answer = solution.reorderList(head);
    // Print out the reversed LL for debugging.
    std::cout << "Answer: ";
    while(answer){
        std::cout << answer->val << " ";
        answer = answer->next;
    }
    std::cout << std::endl;
    return 0;
} 