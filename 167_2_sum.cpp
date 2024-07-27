#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int front = 0;
        int back = numbers.size()-1;
        while (front < back){
            if(numbers[front] + numbers[back] > target){
                back--;
            }else if(numbers[front] + numbers[back] < target){
                front++;
            }else{
                return {front+1, back+1};
            }
        }
        return {front+1, back+1};
    }
};

int main(){
    Solution solution;;
    vector<int> input_ = {2,7,11,15};
    int target = 9;
    vector<int> answer = solution.twoSum(input_, target);
    for(int item : answer){
        cout << item << endl;
    }
}