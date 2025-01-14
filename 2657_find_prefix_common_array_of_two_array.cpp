#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<map>
#include<set>
#include<string>
#include<algorithm>

#include "utils.h"

using namespace std;

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> hashSetA(A.size()+1, false);
        vector<int> hashSetB(B.size()+1, false);
        vector<int> answer(A.size(), 0);

        for(int i = 0; i < A.size(); ++i){
            if(i > 0){answer[i] = answer[i-1];};
            hashSetA[A[i]] = true;
            hashSetB[B[i]] = true;
            if(hashSetB[A[i]]){
                answer[i]++;
            }
            if(hashSetA[B[i]]){
                answer[i]++;
            }
            if(A[i] == B[i]){
                answer[i]--;
            }
        }
        return answer;
    }
};

int main(){
    Solution solution;
    vector<int> a = {1,3,2,4};
    vector<int> b = {3,1,2,4};
    vector<int> answer = solution.findThePrefixCommonArray(a, b);
    printVector(answer);
}