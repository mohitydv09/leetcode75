#include<iostream>
#include<vector>
#include<queue>

class Solution {
public:
    int snakesAndLadders(std::vector<std::vector<int>>& board) {
        int n = board.size();
        std::vector<bool> visited(n*n, false);
        int currPos = 1;
        std::queue<int> frontier;
        frontier.push(currPos);
        visited[currPos] = true;
        int level = 1;
        while(!frontier.empty()){
            int currSize = frontier.size();
            for(int i = 0; i < currSize; ++i){
                int currItem = frontier.front(); frontier.pop();
                // if(visited[currItem]){
                //     continue;
                // }
                visited[currItem] = true;
                for(int k = 0; k < 6; ++k){
                    if(currItem + k + 1 == n*n){
                        return level;
                    }else if(currItem + k + 1 < n*n){
                        // Check it this is snake or ladder.
                        int nextPos = nextPosition(board, n, currItem + k + 1);
                        if(nextPos == n*n){return level;}
                        if(nextPos == -1){
                            if(!visited[currItem + k + 1]){
                                frontier.push(currItem + k + 1);
                                visited[currItem + k + 1] = true;
                            }
                        }else{
                            if(!visited[nextPos]){
                                frontier.push(nextPos);
                                visited[nextPos] = true;
                            }
                        }
                    }                    
                }
            }
            level++;
        }
        return level;
    }

private:
    int nextPosition(const std::vector<std::vector<int>>& board,const int& n, const int& pos){
        int colCount = (pos-1)%n;
        int rowCount = (pos-1)/n;
        if(rowCount%2 == 0){
            return board[n-1-rowCount][colCount];
        }else{
            return board[n-1-rowCount][n-1-colCount];
        }
    }
};

int main(){
    Solution solution;
    std::vector<std::vector<int>> board = { {-1,-1,-1,-1,-1,-1},
                                            {-1,-1,-1,-1,-1,-1},
                                            {-1,-1,-1,-1,-1,-1},
                                            {-1,35,-1,-1,13,-1},
                                            {-1,-1,-1,-1,-1,-1},
                                            {-1,15,-1,-1,-1,-1}};
    int answer = solution.snakesAndLadders(board);
    std::cout << "Answer: " << answer << std::endl;
}