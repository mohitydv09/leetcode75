#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution{
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms){
        vector<bool> visited(rooms.size(),false);
        stack<int> frontier;
        visited[0] = true;
        // Push Everthing in the 0th room to frontier.
        for(int room : rooms[0]){
            frontier.push(room);
        }
        while(!frontier.empty()){
            // Go to the room
            int curr_room = frontier.top();
            visited[curr_room] = true;
            frontier.pop();
            for (int room : rooms[curr_room]){
                if(visited[room]==false){
                    frontier.push(room);
                }
            }
        }
        for(bool item : visited){
            if(item == false){
                return false;
            }
        }
        return true;
    }
};

int main(){
    Solution solution_instance;
    vector<vector<int>> input = {{1},{2},{},{}};
    cout << "Answer : " << solution_instance.canVisitAllRooms(input) << endl;
    return 0;
}