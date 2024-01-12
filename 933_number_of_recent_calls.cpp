#include <iostream>
#include <queue>

using namespace std;

class RecentCounter {
public:
    RecentCounter() {
        // Don't need anything here.
    }
    
    int ping(int t) {
        // Add t to queue.
        requests.push(t);
        // Remove form items that are not to be counted.
        while(requests.front() < t-3000){
            requests.pop();
        }
        return requests.size();
    }

private:
    queue<int> requests;
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */

int main(){
    RecentCounter* obj = new RecentCounter;
    int t = 10;
    int param_1 = obj->ping(t);
    cout << "return param 1 is : " << param_1 << endl;
    return 0;
} 