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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1){return list2;};
        if(!list2){return list1;};
        ListNode* mergedHead = nullptr;
        if(list1->val < list2->val){
            mergedHead = list1;
            list1 = list1->next;
        }else{
            mergedHead = list2;
            list2 = list2->next;
        }
        ListNode* mergedIter = mergedHead;
        while(list1 || list2){
            if(!list1){
                mergedIter->next = list2;
                return mergedHead;
            }else if (!list2){
                mergedIter->next = list1;
                return mergedHead;
            }
            // As both are there we check which is larger.
            if(list1->val < list2->val){
                mergedIter->next = list1;
                list1 = list1->next;
            }else{
                mergedIter->next = list2;
                list2 = list2->next;
            }
            mergedIter = mergedIter->next;
        }
        return mergedHead;
    }
};

int main(){
    Solution solution;
    std::vector<int> input1 = {1,2,3,4,5};
    std::vector<int> input2 = {1,2,3,4,5, 6, 6, 7, 10};

    ListNode* head1 = new ListNode(input1.back());
    for (int i = input1.size()-2; i >= 0; --i){
        head1 = new ListNode(input1[i], head1);
    }
    ListNode* head2 = new ListNode(input2.back());
    for (int i = input2.size()-2; i >= 0; --i){
        head2 = new ListNode(input2[i], head2);
    }
    
    ListNode* answer = solution.mergeTwoLists(head1, head2);
    // Print out the reversed LL for debugging.
    std::cout << "Answer: ";
    while(answer){
        std::cout << answer->val << " ";
        answer = answer->next;
    }
    std::cout << std::endl;
    return 0;
} 