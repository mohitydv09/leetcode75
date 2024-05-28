// /** 
//  * Forward declaration of guess API.
//  * @param  num   your guess
//  * @return 	     -1 if num is higher than the picked number
//  *			      1 if num is lower than the picked number
//  *               otherwise return 0
//  * int guess(int num);
//  */
#include <iostream>
using namespace std;

int guess(int num){
    int pick = 2;
    if (num > pick){return -1;} 
    else if(num < pick){return 1;}
    else{return 0;}
}


class Solution {
public:
    int guessNumber(int n) {
        // Make a Guess.
        int start = 1;
        int end = n;
        int num = (start + end)/2;
        while(guess(num) != 0){
            if (guess(num) == -1){
                end = num;
                num = (start + end)/2;
            }else if(guess(num) == 1){
                start = num;
                num = (start + end)/2 + 1;
            }
        }
        return num;
    }
};

int main(){
    Solution solution_instance;
    int n = 1;
    int ans = solution_instance.guessNumber(n);
    return ans;
}