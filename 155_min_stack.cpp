#include<iostream>

class MinStack{
    struct Node{
        int value;
        int minValue;
        Node *next;
    };
    Node *stackHead;

public:
    MinStack() {
        stackHead = nullptr;
    }

    void push(int val) {
        Node* new_head = new Node;
        new_head->value = val;
        new_head->next = stackHead;
        if(stackHead == nullptr){
            new_head->minValue = val;
        }else{
            if(val < stackHead->minValue){
                new_head->minValue = val;
            }else{
                new_head->minValue = stackHead->minValue;
            }
        }
        stackHead = new_head;
    }

    int top() {
        return stackHead->value;
    }

    void pop(){
        if (stackHead == nullptr){
            return;
        }
        stackHead = stackHead->next;
    }

    int getMin() {
        return stackHead->minValue;
    }
};

int main(){
    MinStack();
    MinStack my_stack;
    my_stack.push(10);
    my_stack.push(5);
    my_stack.push(100);

    std::cout << my_stack.getMin() << std::endl;
    my_stack.pop();
    std::cout << my_stack.getMin() << std::endl;
}