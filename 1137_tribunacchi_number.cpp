class Solution {
public:
    int tribonacci(int n) {
        if(n < 1){
            return 0;
        }else if(n < 3){
            return 1;
        }
        int Tn1 = 1;
        int Tn2 = 1;
        int Tn3 = 0;
        for(int i = 3; i <= n; i++){
            int T_new = Tn1+Tn2+Tn3;
            Tn3 = Tn2;
            Tn2 = Tn1;
            Tn1 = T_new;
        }
        return Tn1;
    }
};