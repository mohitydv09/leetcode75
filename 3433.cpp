#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        vector<int> mentions(numberOfUsers, 0);
        vector<int> online(numberOfUsers, -100);

        // Sort the items
        sort(events.begin(), events.end(), [](const vector<string>& a, const vector<string>& b){
            if (stoi(a[1]) == stoi(b[1])){
                return a[0] > b[0];
            } else {
                return stoi(a[1]) < stoi(b[1]);
            }
        });

        // Take care of sequence, If the timestamp is same we need to check
        for(int i = 0; i < events.size(); ++i){
            int timestamp = stoi(events[i][1]);
            cout << "i: " << i << endl;
            cout << "EV: " << events[i][0] << " " << events[i][1] << " " << events[i][2] << endl;
            if (events[i][0] == "MESSAGE"){
                if (events[i][2] == "ALL"){
                    for (int i = 0; i < mentions.size(); ++i){
                        mentions[i]++;
                    }
                } else if (events[i][2] == "HERE"){
                    for (int i = 0; i < mentions.size(); ++i){
                        // If Online 
                        if (online[i] <= timestamp - 60){
                            mentions[i]++;
                        }
                    }
                } else {
                    // Process all
                    stringstream ss(events[i][2]);
                    string word;
                    while(ss >> word){
                        int userId = stoi(word.substr(2));
                        mentions[userId]++;
                    }
                }
            } else {
                // Offline, set the time to the timestamp as the user goes offline
                int userId = stoi(events[i][2]);
                online[userId] = stoi(events[i][1]);
            }
        }
        return mentions;
    }
};

int main(){
    Solution solution;
    vector<vector<string>> events = {{"MESSAGE","10","id1 id0"},{"OFFLINE","11","0"},{"MESSAGE","71","HERE"}};
    
    vector<int> answer = solution.countMentions(2, events);
    cout << "Answer: ";
    for(int i = 0; i < answer.size(); ++i){
        cout << answer[i] << ' ';
    }
    cout << endl;
}