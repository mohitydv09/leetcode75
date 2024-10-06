#include<iostream>
class Trie{
private:
    struct TrieNode{
        TrieNode* children[26];
        bool isWord = false;
    };
    TrieNode* root;

public:
    Trie(){
        root = new TrieNode();
    };

    void insert(std::string word){
        TrieNode* currNode = root;
        for (int i = 0; i < word.size(); ++i){
            int currChar = word[i] - 'a';
            if(currNode->children[currChar] == nullptr){
                currNode->children[currChar] = new TrieNode();
            }
            currNode = currNode->children[currChar];
        }
        currNode->isWord = true;
    };

    bool search(std::string word){
        TrieNode* currNode = root;
        for (int i = 0; i < word.size(); i++){
            int currChar = word[i] - 'a';
            if(currNode->children[currChar] == nullptr){
                return false;
            }
            currNode = currNode->children[currChar];
        }
        return currNode->isWord;
    };

    bool startsWith(std::string prefix){
        TrieNode* currNode = root;
        for (int i = 0; i < prefix.size(); i++){
            int currChar = prefix[i] - 'a';
            if(currNode->children[currChar] == nullptr){
                return false;
            }
            currNode = currNode->children[currChar];
        }
        return true;
    };
};

int main(){
    Trie* obj = new Trie();  // new helps in dynamic memory allocation.

    obj->insert("hello");
    std::cout << obj->search("hello") << std::endl;
};