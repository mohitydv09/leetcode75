#include <iostream>
#include <vector>
#include <queue>
#include <cctype>
using namespace std;

class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> r_queue;
        queue<int> d_queue;
        // Make a queue for both of them.
        for (int i = 0; i < senate.size(); i++){
            if(senate[i] == 'R'){
                r_queue.push(i);
            }else{
                d_queue.push(i);
            }
        }
 
        while(!r_queue.empty() && !d_queue.empty()){
            int r = r_queue.front();
            r_queue.pop();
            int d = d_queue.front();
            d_queue.pop();
            if( r < d){
                r_queue.push(r+senate.size());
            }else{
                d_queue.push(d+senate.size());
            }
        }
        if (r_queue.empty()){
            return "Dire";
        }else{
            return "Radiant";
        }
    }
};

int main(){
    Solution solution_instance;
    string s = "RDD";
    cout << solution_instance.predictPartyVictory(s);
    return 0;
} 