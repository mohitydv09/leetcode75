#include<iostream>
#include<vector>

class Solution {
public:
    void solve(std::vector<std::vector<char>>& board) {
        //We need to run bfs from the corners which have zero.
        int rows = board.size();
        int cols = board[0].size();
        std::vector<std::vector<bool>> captured(rows, std::vector<bool>(cols, true));

        for (int row = 0; row < rows; ++row){
            bfsSearch(row ,0, board, captured);
            bfsSearch(row, cols-1, board, captured);
        }
        for (int col = 0; col < cols; ++ col){
            bfsSearch(0, col, board, captured);
            bfsSearch(rows-1, col, board, captured);
        }
        for (int row = 0; row < rows; ++row){
            for (int col = 0; col < cols; ++col){
                if(captured[row][col]){
                    board[row][col] = 'X';
                }
            }
        }

    }

private:
    void bfsSearch(int row, int col, std::vector<std::vector<char>>& board, std::vector<std::vector<bool>>& captured){
        if(row < 0 || row >= board.size() || col < 0 || col >= board[0].size()){
            // Out of bounds.
            return;
        }
        if(!captured[row][col]){
            return;
        }
        if(board[row][col] == 'X'){
            return;
        }
        captured[row][col] = false;
        bfsSearch(row+1, col, board, captured);
        bfsSearch(row-1, col, board, captured);
        bfsSearch(row, col+1, board, captured);
        bfsSearch(row, col-1, board, captured);
    }
};

int main(){
    Solution solution;
    std::vector<std::vector<char>> board = {{'X','X','X','X'},{'X','O','O','X'},{'X','X','O','X'},{'X','O','X','X'}};
    solution.solve(board);
    std::cout << "Answer:" << std::endl;
    for (auto row : board){
        for(auto item : row){
            std::cout << item << " ";
        }
        std::cout << std::endl;
    }
}