#include<iostream>
#include<unordered_map>
#include<list>

class LRUCache {
struct LLNode{
    int key;
    int val;
    LLNode* next;
    LLNode* prev;
    // Constructors
    LLNode(): key(0), val(0), next(nullptr), prev(nullptr) {} ;
    LLNode(int _key, int _val): key(_key), val(_val), next(nullptr), prev(nullptr) {};
};
private:
    int cap;
    std::unordered_map<int, LLNode*> hashMap;
    LLNode* left = new LLNode();
    LLNode* right = new LLNode();
    
public:
    LRUCache(int capacity) {
        cap = capacity;
        left->next = right; 
        right->prev = left;
    }

    void removeNode(LLNode* &node){
        if (node->prev){
            node->prev->next = node->next;
        }
        if (node->next){
            node->next->prev = node->prev;
        }
        // node->prev->next = node->next;
        // node->next->prev = node->prev;
    }

    void insertBack(LLNode* &node){
        node->next = right;
        node->prev = right->prev;
        node->prev->next = node;
        right->prev = node;
    }
    
    int get(int key) {
        if(hashMap.count(key) > 0){
            removeNode(hashMap[key]);
            insertBack(hashMap[key]);
            return hashMap[key]->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (hashMap.count(key) > 0){
            removeNode(hashMap[key]);
        }
        LLNode* newNode = new LLNode(key, value);
        hashMap[key] = newNode;
        insertBack(hashMap[key]);

        if( hashMap.size() > cap){
            LLNode* lru = left->next;
            removeNode(lru);
            hashMap.erase(lru->key);
        }
    }
};

int main(){
    LRUCache* obj = new LRUCache(2);
    obj->put(5,10);
    // int value = obj->get(5);
    // std::cout << "Value: " << value << std::endl;
}