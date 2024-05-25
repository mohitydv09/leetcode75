#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class SmallestInfiniteSet {
public:
    priority_queue<int, vector<int>, greater<int>> infiniteSet;
    array<int, 1002> in_pq;
    SmallestInfiniteSet() {
        for (int i = 1; i < 1001; i++){
            infiniteSet.push(i);
            in_pq[i] = 1;
        }
    }
    
    int popSmallest() {
        int top = infiniteSet.top();
        in_pq[top] = 0;
        infiniteSet.pop();
        return top;
    }
    
    void addBack(int num) {
        if(in_pq[num] == 0){
            infiniteSet.push(num);
            in_pq[num] = 1;
        }
    }
};

int main(){
    SmallestInfiniteSet solution_instance;
    vector<string> calls= {"SmallestInfiniteSet", "addBack", "popSmallest", "popSmallest", "popSmallest", "addBack", "popSmallest", "popSmallest", "popSmallest"};
    vector<int> items = {-1, 2, -1, -1, -1, 1, -1, -1, -1};
    // for(int i = 0; i< calls.size(); i++){
    //     if (calls[i] == "SmallestInfiniteSet"){
    //         SmallestInfiniteSet solution_instance;
    //     }
    // }
    // cout << "Answer : " << solution_instance.findKthLargest(input,k) << endl;
    return 0;
}