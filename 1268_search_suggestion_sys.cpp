#include<iostream>
#include<stack>
using namespace std;

class Solution{
private:
    class Trie{
        private:
            struct TrieNode{
                TrieNode* children[26] = {nullptr};
                bool isWord = false;
            };
            TrieNode* root;

        public:
            Trie(){
                root = new TrieNode();
            };

            void insert(string word){
                TrieNode* currNode = root;
                for(int i = 0; i < word.size(); i++){
                    int currChar = word[i] - 'a';
                    if(currNode->children[currChar] == nullptr){
                        currNode->children[currChar] = new TrieNode;
                    }
                    currNode = currNode->children[currChar];
                }
                currNode->isWord = true;
            };

            vector<string> getSimilar(string word){
                vector<string> similar;
                TrieNode* currNode = root;
                for(int i = 0; i < word.size(); i++){
                    int currChar = word[i] - 'a';
                    if(currNode->children[currChar] == nullptr){
                        return similar;
                    }
                    currNode = currNode->children[currChar];
                }
                dfs(currNode, similar, word);
                return similar;
            }

            void dfs(TrieNode* currNode, vector<string> &similar, string &currString){
                if(similar.size() >=3 ){
                    return;
                }
                if(currNode == nullptr){
                    return;
                }
                if (currNode->isWord){
                    similar.push_back(currString);
                }
                for(int i = 0; i < 26; i++){
                    if(currNode->children[i] != nullptr){
                        currString += 'a' + i;
                        dfs(currNode->children[i], similar, currString);
                        currString.erase(currString.size()-1);
                    }
                }
            }
    };

public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord){
        Trie searchTree;

        for(string word : products){
            searchTree.insert(word);
        }
        vector<vector<string>> ans;
        for (int i = 1; i < searchWord.size()+1; i++){
            string sub_word = searchWord.substr(0,i);
            vector<string> currAns = searchTree.getSimilar(sub_word);
            ans.push_back(currAns);
        }
        return ans;
    }
};

int main(){
    Solution obj;
    vector<string> products = {"mobile","mouse","moneypot","monitor","mousepad"};
    string searchWord = "mouse";
    vector<vector<string>> ans = obj.suggestedProducts(products, searchWord);
    for (vector<string> list : ans){
        for(string item : list){
            cout << item << " ";
        }
        cout << endl;
    }

}