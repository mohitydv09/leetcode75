#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<map>
#include<set>
#include<string>
#include<algorithm>

#include "utils.h"

using namespace std;

class NumberContainers {
private:
    unordered_map<int, int> idx2num;
    unordered_map<int, set<int>> num2idxs;

public:
    NumberContainers() {}
    
    void change(int index, int number) {
        if(idx2num.find(index) != idx2num.end()){
            num2idxs[idx2num[index]].erase(index);
        }
        idx2num[index] = number;
        num2idxs[number].emplace(index);
    }
    
    int find(int number) {
        return num2idxs[number].empty() ? -1 : *num2idxs[number].cbegin();
    }
};

int main(){
    NumberContainers* obj = new NumberContainers();
    obj->change(2,10);
    int param_2 = obj->find(10);
    cout << param_2 << endl;
}