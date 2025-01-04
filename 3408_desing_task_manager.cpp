#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<map>
#include<set>

#include "utils.h"

using namespace std;

class TaskManager {

unordered_map<int, pair<int, int>> hashMap; //taskId -> userId, priority
set<pair<int, int>> mySet; // priority, taskId

public:
    TaskManager(vector<vector<int>>& tasks) {
        for(const auto& task : tasks){
            hashMap[task[1]] = {task[0], task[2]};
            mySet.emplace(make_pair(task[2], task[1]));
        }
    }
    
    void add(int userId, int taskId, int priority) {
        hashMap[taskId] = {userId, priority};
        mySet.emplace(make_pair(priority, taskId));
    }
    
    void edit(int taskId, int newPriority) {
        int userId = hashMap[taskId].first;
        rmv(taskId);
        add(userId, taskId, newPriority);
    }
    
    void rmv(int taskId) {
        int taskPriority = hashMap[taskId].second;
        hashMap.erase(taskId);
        mySet.erase(make_pair(taskPriority, taskId));
    }
    
    int execTop() {
        if(mySet.empty()){
            return -1;
        }
        auto [prior, taskId] = *mySet.rbegin();
        int userId = hashMap[taskId].first;
        rmv(taskId);
        return userId;
    }
};

int main(){
    vector<vector<int>> tasks =  {{1,101,10}, {2,102,20}, {3,103,15}};
    TaskManager* obj = new TaskManager(tasks);
    obj->add(4,104,5);
    obj->edit(102,8);
    obj->execTop();
    obj->rmv(101);
}