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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* headIter = head;
        ListNode* nthNode = new ListNode(-1, head);
        int i = 1;
        while(headIter->next){
            if(i < n){
                headIter = headIter->next;
            }else{
                headIter = headIter->next;
                nthNode = nthNode->next;
            }
            i++;
        }
        nthNode->next = nthNode->next->next;
        return (nthNode->val == -1) ? nthNode->next : head;
    }
};

int main(){
    Solution solution;
    std::vector<int> input = {1,2,3,4,5};

    ListNode* head = new ListNode(input.back());
    for (int i = input.size()-2; i >= 0; --i){
        head = new ListNode(input[i], head);
    }
    int n = 5;
    
    ListNode* answer = solution.removeNthFromEnd(head, n);
    // Print out the reversed LL for debugging.
    std::cout << "Answer: ";
    while(answer){
        std::cout << answer->val << " ";
        ListNode* temp = answer;
        answer = answer->next;
        delete temp;
    }
    std::cout << std::endl;
    return 0;
} 