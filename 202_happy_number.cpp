#include<iostream>
#include<unordered_set>

class Solution {
public:
    bool isHappy(int n) {
        std::unordered_set<int> seen;
        while(seen.find(n) == seen.end()){
            seen.emplace(n);
            n = get_next_num(n);
            if(n == 1){
                return true;
            }
        }
        return false;
    }
private:
    int get_next_num(int n){
        int next_num = 0;
        while(n > 0){
            int remainder = n%10;
            next_num += remainder*remainder;
            n /= 10;
        }
        return next_num;
    }
};


int main(){
    Solution solution;
    bool answer = solution.isHappy(2);
    std::cout << "Answer: " << answer << std::endl;
}