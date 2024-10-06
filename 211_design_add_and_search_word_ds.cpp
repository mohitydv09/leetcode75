#include<iostream>

class WordDictionary {
private:
    struct TrieNode{
        TrieNode* children[26] = {nullptr};
        bool isWord = false;
    };
    TrieNode* root;

public:
    WordDictionary() {
        root = new TrieNode;
    }
    
    void addWord(std::string word) {
        TrieNode* iterator = root;
        for(char c : word){
            if(iterator->children[c - 'a'] == nullptr){
                iterator->children[c - 'a'] = new TrieNode;
            }
            iterator = iterator->children[c-'a'];
        }
        iterator->isWord = true;
    }
    
    bool search(std::string word) {
        return searchSubTrie(0, word, root);
    }

private:
    bool searchSubTrie(int idx, const std::string& word, TrieNode* subRoot){
        TrieNode* iterator = subRoot;
        for (int i = idx; i < word.size(); ++i){
            if(word[i] == '.'){
                for(auto child : iterator->children){
                    if(child != nullptr){
                        if(searchSubTrie(i + 1, word, child)){
                            return true;
                        };
                    }
                }
                return false;
            }else{
                if(iterator->children[word[i] - 'a'] == nullptr){
                    return false;
                }
            }
            iterator = iterator->children[word[i]-'a'];
        }
        return iterator->isWord;
    }
};

int main(){
    WordDictionary* obj = new WordDictionary();
    obj->addWord("mohit");
    std::cout << obj->search(".ohit") << std::endl; 
}