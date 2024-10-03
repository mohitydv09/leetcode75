#include<iostream>
#include<vector>
#include<string>

class Solution {
public:
    bool exist(std::vector<std::vector<char>>& board, std::string word) {
        int rows = board.size();
        int cols = board[0].size();

        for(int row = 0; row < rows; ++row){
            for(int col = 0; col < cols; ++col){
                if(search(board, word, row, col, 0)){
                    return true;
                }
            }
        }
        return false;
    }

private:
    bool search(std::vector<std::vector<char>>& board, const std::string &word, int row, int col, int idx){
        if(idx == word.size()){
            return true;
        }
        if(row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || board[row][col] != word[idx]){
            return false;
        }
        char temp = board[row][col];
        board[row][col] = '#';

        bool found =    search(board, word, row + 1, col, idx + 1) ||
                        search(board, word, row - 1, col, idx + 1) ||
                        search(board, word, row, col + 1, idx + 1) ||
                        search(board, word, row, col - 1, idx + 1);

        board[row][col] = temp;
        return found;
    }
};

int main(){
    Solution solution;
    std::vector<std::vector<char>> board = {{'A','B','C','E'},
                                            {'S','F','C','S'},
                                            {'A','D','E','E'}};
    std::string word = "ABCCED";
    bool answer = solution.exist(board, word);
    std::cout << "Answer: " << answer << std::endl;
}