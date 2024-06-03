#include<iostream>

using namespace std;

class Solution{
public:
    int numTilings(int n){
        int An = 2; // for n=2
        int An1 = 1; // for n=1
        int An2 = 1; //for n=0
        int MOD = 1000000007;
        if(n == 1){
            return An1;
        }else if(n == 2){
            return An;
        }

        for (int i = 3; i <= n; i++){
            int new_val = (2*An)%MOD + An2;
            An2 = An1%MOD;
            An1 = An%MOD;
            An = new_val%MOD;
        }

        return An;
    }
};

int main(){
    Solution solution_instance;
    int n = 4;
    cout << "Ans : " << solution_instance.numTilings(n) << endl;
}