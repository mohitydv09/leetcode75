#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Go into each row.
        for (const vector<char>& row : board){
            map<int, int> hashMap;
            for(int i = 0; i < row.size(); ++i){
                if (row[i] != '.'){
                    if(hashMap[row[i]]>0){
                        return false;
                    }else{
                        hashMap[row[i]]++;
                    }
                }
            }
        }

        // Go into columns.
        for (int j = 0; j < board.size(); ++j){
            map<int, int> hashMap;
            for (int i = 0; i < board.size(); ++i){
                if (board[i][j] != '.'){
                    if(hashMap[board[i][j]] > 0){
                        return false;
                    }else{
                        hashMap[board[i][j]]++;
                    }
                }
            }
        }

        // Check small boxex.
        for(int ii = 0; ii < 3; ++ii){
            for (int jj = 0; jj < 3; ++jj){
                //check box.
                map<int,int> hashMap;
                for (int i = 0; i < 3; ++i){
                    for (int j = 0; j < 3; ++j){
                        if (board[3*ii + i][3*jj + j] != '.'){
                            if (hashMap[board[3*ii + i][3*jj + j]] > 0){
                                return false;
                            }else{
                                hashMap[board[3*ii + i][3*jj + j]]++;
                            }
                        }
                    }
                }
            }
        }
        return true;
    }
};

int main(){
    Solution solution;
    vector<vector<char>> board ={{'8','3','.','.','7','.','.','.','8'}
                                ,{'6','.','.','1','9','5','.','.','.'}
                                ,{'.','9','8','.','.','.','.','6','.'}
                                ,{'8','.','.','.','6','.','.','.','3'}
                                ,{'4','.','.','8','.','3','.','.','1'}
                                ,{'7','.','.','.','2','.','.','.','6'}
                                ,{'.','6','.','.','.','.','2','8','.'}
                                ,{'.','.','.','4','1','9','.','.','5'}
                                ,{'.','.','.','.','8','.','.','7','9'}};
    bool answer = solution.isValidSudoku(board);
    cout << "Answer: " << answer << endl;
}