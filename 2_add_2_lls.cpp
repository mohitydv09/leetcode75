#include<iostream>
#include<vector>

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
        ListNode* solution = new ListNode;
        ListNode* solutionIter = solution;
        int carry = 0;
        while(l1 || l2){
            int first = (l1) ? l1->val : 0;
            int second = (l2) ? l2->val : 0;
            int sum = first + second + carry;
            std::cout << "First:  " << first << " Second: " << second << " Carry: " << carry << std::endl;
            solutionIter->val = sum%10;
            carry = sum/10;
            l1 = (l1) ? l1->next : nullptr;
            l2 = (l2) ? l2->next : nullptr;
            if(l1 || l2){
                solutionIter->next = new ListNode;
                solutionIter = solutionIter->next;
            }
        }
        if(carry > 0){
            solutionIter->next = new ListNode(carry);
        }
        return solution;
    }
};

int main() {
    Solution solution;
    std::vector<int> input1 = {9,9,9,9,9,9,9};
    std::vector<int> input2 = {9,9,9,9};

    ListNode* head1 = new ListNode(input1.back());
    for (int i = input1.size()-2; i >= 0; --i){
        head1 = new ListNode(input1[i], head1);
    }
    ListNode* head2 = new ListNode(input2.back());
    for (int i = input2.size()-2; i >= 0; --i){
        head2 = new ListNode(input2[i], head2);
    }

    ListNode* answer = solution.addTwoNumbers(head1, head2);

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