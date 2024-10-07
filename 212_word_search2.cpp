#include<iostream>
#include<vector>
#include<string>

class Solution {
private:
    struct TrieNode{
        TrieNode* children[26] = {nullptr};
        bool isWord = false;
    };
    TrieNode* root;
    std::vector<std::string> answer;

public:
    std::vector<std::string> findWords(std::vector<std::vector<char>>& board, std::vector<std::string>& words) {
        int num_rows = board.size();
        int num_cols = board[0].size();

        // Initialize root.
        root = new TrieNode;

        // Form the Prefix Tree from words.
        for (auto word: words){
            addWord(word);
        }

        // Iterate over the board to see if word exists.
        for (int row = 0; row < num_rows; ++row){
            for (int col = 0; col < num_cols; ++col){
                dfs(row, col, board, root, "");
            }
        }
        return answer;
    }

private:
    void dfs(int row, int col, std::vector<std::vector<char>>& board, TrieNode* currRoot, std::string currWord){
        if(row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || board[row][col] == '#'){
            return;
        }

        // Check if the item exist in Trie, return if not.
        if(currRoot->children[board[row][col]-'a'] == nullptr){
            return;
        }

        currRoot = currRoot->children[board[row][col]-'a'];
        currWord.push_back(board[row][col]);
        if(currRoot->isWord){
            answer.push_back(currWord);
            currRoot->isWord = false;
        }

        char temp = board[row][col];
        board[row][col] = '#';
        
        // Go deep.
        dfs(row+1, col, board, currRoot, currWord);
        dfs(row-1, col, board, currRoot, currWord);
        dfs(row, col+1, board, currRoot, currWord);
        dfs(row, col-1, board, currRoot, currWord);

        currWord.pop_back();
        board[row][col] = temp;
    }

    void addWord(std::string& word){
        TrieNode* iterator = root;
        for(int i = 0; i < word.size(); ++i){
            if(iterator->children[word[i]-'a'] == nullptr){
                iterator->children[word[i]-'a'] = new TrieNode;
            }
            iterator = iterator->children[word[i]-'a'];
        }
        iterator->isWord = true;
    }
};

int main(){
    Solution solution;
    std::vector<std::vector<char>> board = {{'o','a','a','n'},
                                            {'e','t','a','e'},
                                            {'i','h','k','r'},
                                            {'i','f','l','v'}};

    std::vector<std::string> words = {"oath","pea","eat","rain"};

    std::vector<std::string> answer = solution.findWords(board, words);
    std::cout << "Answer: " << std::endl;
    for(auto item : answer){
        std::cout << item << std::endl;
    }
}