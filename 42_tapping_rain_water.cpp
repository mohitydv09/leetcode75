#include <iostream>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int front = 0;
        int back = height.size()-1;
        int maxLeft = 0;
        int maxRight = 0;
        int answer = 0;
        while (front < back){
            if(maxLeft <= maxRight){
                int water = min(maxLeft, maxRight) - height[front];
                if (water > 0) { answer += water; }
                if(height[front] > maxLeft){
                    maxLeft = height[front];
                }
                front++;
            }else{
                int water = min(maxLeft, maxRight) - height[back];
                if (water > 0) { answer += water; }
                if(height[back] > maxRight){
                    maxRight = height[back];
                }
                back--;
            }
        }
        return answer;
    }
};

int main(){
    Solution solution;;
    vector<int> input_ = {0,1,0,2,1,0,1,3,2,1,2,1};
    int answer = solution.trap(input_);
    cout << "Answer: " << answer << endl;
}