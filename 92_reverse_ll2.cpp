#include<iostream>
#include<vector>

struct ListNode{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr){}
    ListNode(int x) : val(x), next(nullptr){}
    ListNode(int x, ListNode* next) : val(x), next(next){}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head || left == right){return head;}

        // Creating a dummy node to handle the cases when left is 1.
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prefixLast = dummy;

        //Move the prefixLast to the node before reversal
        for(int i = 1; i < left; ++i){
            prefixLast = prefixLast->next;
        }

        // Start reversing now.
        ListNode* reverseStart = prefixLast->next;
        ListNode* iter = reverseStart;
        ListNode* prev = nullptr;

        for(int i = 0; i <= right-left; ++i){
            ListNode* nextNode = iter->next;
            iter->next = prev;
            prev = iter;
            iter = nextNode;
        }
        prefixLast->next = prev;
        reverseStart->next = iter;

        return dummy->next;
    }
};

int main(){
    Solution solution;
    std::vector<int> input = {1,2,3,4,5,6,7};
    int left = 3, right = 5;
    ListNode* head = new ListNode(input[0]);
    ListNode* iter = head;
    for(int i = 1; i < input.size(); ++i){
        ListNode* new_node = new ListNode(input[i]);
        iter->next = new_node;
        iter = iter->next;
    }
    ListNode* answer = solution.reverseBetween(head, left, right);

    // Print Answer.
    std::cout << "Answer: ";
    while(answer){
        std::cout << answer->val << " ";
        answer = answer->next;
    }
    std::cout << std::endl;
}