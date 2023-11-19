#include <iostream>
#include <string>
using namespace std;


class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        // First find the GCD of length of the string as that length x can only be the solution.
        int a,b;
        string large, small;
        if ( str1.length() >= str2.length()){
            a = str1.length();
            b = str2.length();
            large = str1;
            small = str2;
        } else {
            b = str1.length();
            a = str2.length();
            large = str2;
            small = str1;
        }
        int gcd_num = gcdnumbers(a,b);
        // For all substrings of smaller substring of size gcd_num try if the larger one has the same substring
        string one_str_to_rule_them_all = small.substr(0,gcd_num);
        for ( int i = 0 ; i < (a/gcd_num) ; i++){
            string sub_str = large.substr(i * gcd_num , gcd_num);
            if(sub_str != one_str_to_rule_them_all){
                return "";
            }
        }
        for ( int j = 0 ; j < (b/gcd_num) ; j++){
            string sub_str2 = small.substr( j * gcd_num , gcd_num);
            if(sub_str2 != one_str_to_rule_them_all){
                return "";
            }
        }
        return one_str_to_rule_them_all;
    }
    int gcdnumbers(int a, int b){
        int small = min(a,b);
        int large = max(a,b);
        int c = large - small;
        if(c==0){
            return large;
        } else {
            return gcdnumbers(c, small);
        }
    }
};


int main(){
    Solution solution_instance;
    cout << solution_instance.gcdOfStrings("ABABAB","ABAB");
    return 0;
}