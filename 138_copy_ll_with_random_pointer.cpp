#include<iostream>
#include<vector>
#include<unordered_map>

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        std::unordered_map<Node*, Node*> old2new;
        Node* iter = head;
        while(iter){
            Node* newNode = new Node(iter->val);
            old2new[iter] = newNode;
            iter = iter->next;
        }
        iter = head;
        while(iter){
            Node* currNode = old2new[iter];
            currNode->next = old2new[iter->next];
            currNode->random = old2new[iter->random];
            iter = iter->next;
        }
        return old2new[head];
    }
};

int main() {
    
}