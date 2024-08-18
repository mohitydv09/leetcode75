#include <iostream>
#include <vector>
#include <stack>

struct ListNode{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // Edge Cases when there is only one value or less.
        if(!head || !head->next) {return head;};
        ListNode* reverseLL = nullptr;
        while(head){
            ListNode* tempNode = head->next;
            head->next = reverseLL;
            reverseLL = head;
            head = tempNode;
        }
        return reverseLL;
    }
};

int main(){
    Solution solution;
    std::vector<int> input = {1,2,3,4,5};

    ListNode* head = new ListNode(input.back());
    for (int i = input.size()-2; i >= 0; --i){
        head = new ListNode(input[i], head);
    }
    
    ListNode* answer = solution.reverseList(head);
    // Print out the reversed LL for debugging.
    std::cout << "Answer: ";
    while(answer){
        std::cout << answer->val << " ";
        answer = answer->next;
    }
    std::cout << std::endl;
    return 0;
} 