#include<iostream>

using namespace std;

class Solution{
public:
    int minFlips(int a, int b, int c){
        bitset<16> bit_a(a);
        bitset<16> bit_b(b);
        bitset<16> bit_c(c);
        int ans = 0;
        for (int i = 0; i < bit_a.size(); i++){
            if((bit_a[i] | bit_b[i]) != bit_c[i]){
                ans += 1;
                if(bit_a[i] == 1 && bit_b[i] == 1){
                    ans += 1;
                }
            }
        }
        return ans;
    }
};

int main(){
    Solution solution_instance;
    int a = 2;
    int b = 6;
    int c = 5;
    cout << "Ans : " << solution_instance.minFlips(a, b, c) << endl;
}