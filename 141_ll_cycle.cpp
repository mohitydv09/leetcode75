#include<iostream>
#include<vector>
#include<unordered_map>

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    bool hasCycle(ListNode *head) {
        // Error Handling
        if (!head || !head->next){return false;}
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(slow != fast){
            if(!fast->next || !fast->next->next){
                return false;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        return true;
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