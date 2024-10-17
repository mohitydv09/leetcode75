#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<queue>

class Solution {
public:
    int ladderLength(std::string beginWord, std::string endWord, std::vector<std::string>& wordList) {

        // Check for the presence of end word.
        bool endWordPresent = false;
        for(int i = 0; i < wordList.size(); ++i){
            if(wordList[i] == endWord){
                endWordPresent = true;
            }
        }
        if(!endWordPresent){return 0;}

        std::unordered_map<std::string, std::vector<std::string>> adjList;
        // Push the beginword to the list.
        wordList.push_back(beginWord);
        for(auto word : wordList){
            for(int i = 0; i < word.size(); ++i){
                std::string newItem = word;
                newItem[i] = '#';
                adjList[newItem].push_back(word);
            }
        }
        
        // Do the BFS.
        std::unordered_set<std::string> visited;
        std::queue<std::string> frontier;
        frontier.push(beginWord);
        visited.insert(beginWord);
        int depth = 0;
        while(!frontier.empty()){
            depth++;
            // std::cout << "frontier size: " << frontier.size() << std::endl;
            int currFrontierSize = frontier.size();
            
            for(int i = 0; i < currFrontierSize; ++i){
                std::string currWord = frontier.front(); frontier.pop();
                if(currWord == endWord){
                    return depth;
                }
                visited.insert(currWord);
                for (int j = 0; j < currWord.size(); ++j){
                    std::string newItem = currWord;
                    newItem[j] = '#';
                    for(auto neigh : adjList[newItem]){
                        if(visited.find(neigh) == visited.end()){
                            // This was not visited.
                            frontier.push(neigh);
                        }
                    }
                }
            }

        }
        return 0; // This means that the item was not found in the graph.
    }
};

int main(){
    Solution solution;
    std::string beginWord = "hit";
    std::string endWord = "cog";
    std::vector<std::string> wordList = {"hot","dot","dog","lot","log","cog"};
    std::cout << "Answer: " << solution.ladderLength(beginWord, endWord, wordList) << std::endl;
}
