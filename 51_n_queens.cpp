#include<iostream>
#include<vector>
#include<string>

class Solution {
std::vector<std::vector<std::string>> answer;
public:
    std::vector<std::vector<std::string>> solveNQueens(int n){
        std::string rows(n, '.');
        std::vector<std::string> currBoard(n, rows);
        std::vector<std::string> available(n, rows);
        backTrack(0, n, currBoard, available);
        return answer;
    }
private:
    void backTrack(int idx, int& n, std::vector<std::string>& currBoard, std::vector<std::string>& available){
        if(idx >= n){
            answer.push_back(currBoard);
            return;
        }
        for (int i = 0; i < n; ++i){
            if(available[idx][i] == '.'){
                std::vector<std::string> oldAvailable = available;
                currBoard[idx][i] = 'Q';
                for(int j = idx; j < n; ++j){
                    int depth = j-idx;
                    available[j][i] = 'X';
                    if(i-depth >= 0){
                        available[j][i-depth] = 'X';
                    }
                    if(i+depth < n){
                        available[j][i+depth] = 'X';
                    }
                }
                backTrack(idx+1, n, currBoard, available);
                currBoard[idx][i] = '.';
                available = oldAvailable;
            }
        }
    }
};

int main(){
    Solution solution;
    std::vector<std::vector<std::string>> answer = solution.solveNQueens(5);
    std::cout << "Valid Boards." << std::endl;
    for (auto board: answer){
        std::cout << "Board: " << std::endl;
        for (auto row : board){
            std::cout << row << std::endl;
        }
    }
}