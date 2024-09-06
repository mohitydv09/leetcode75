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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummyNode = new ListNode(-1, head);
        ListNode* groupPrev = dummyNode;

        while (true){
            if(!groupPrev->next){return dummyNode->next;}
            ListNode* start = groupPrev->next;
            ListNode* end = groupPrev;
            for (int i = 0; i < k; ++i){
                if(!end->next){
                    return dummyNode->next;
                }else{
                    end = end->next;
                }
            }
            ListNode* groupNext = end->next;
            auto reveredLL = reverseList(start, end);
            groupPrev->next = reveredLL.first;
            reveredLL.second->next = groupNext;
            groupPrev = start;
        }
        return dummyNode->next;
    }

    std::pair<ListNode*, ListNode*> reverseList(ListNode* head, ListNode* end) {
        if (head == end){return {head,end};};
        ListNode* reversedEnd = head;

        ListNode* reverseLL = nullptr;
        while(head != end){
            ListNode* tempNode = head->next;
            head->next = reverseLL;
            reverseLL = head;
            head = tempNode;
        }
        head->next = reverseLL;
        return {end, reversedEnd};
    }
};

int main(){
    Solution solution;
    std::vector<int> input = {1,2};

    ListNode* head1 = new ListNode(input.back());
    for (int i = input.size()-2; i >= 0; --i){
        head1 = new ListNode(input[i], head1);
    }
    
    ListNode* answer = solution.reverseKGroup(head1, 2);

    // Print out the LL for debugging.
    std::cout << "Answer: ";
    while(answer){
        std::cout << answer->val << " ";
        answer = answer->next;
    }
    std::cout << std::endl;
    return 0;
} 