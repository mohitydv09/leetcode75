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
    vector<int> closestPrimes(int left, int right) {
        vector<int> primes_in_range = find_primes_in_range_n_sieve(left, right);

        if(primes_in_range.size() < 2){
            return {-1, -1};
        }
        vector<int> answer = {primes_in_range[0], primes_in_range[1]};
        for(int i = 2; i < primes_in_range.size(); ++i){
            if(primes_in_range[i] -  primes_in_range[i-1] < answer[1] - answer[0]){
                answer[0] = primes_in_range[i-1];
                answer[1] = primes_in_range[i];
            } 
        }
        return answer;
    }

private:
    vector<int> find_primes_in_range_n_sieve(int left, int right){
        vector<int> primes = {};
        vector<bool> visited(right+1, false);
        for(int i = 2; i < right+1; ++i){
            if(!visited[i]){
                // Add this to the prime list.
                if(i >= left){
                    primes.push_back(i);
                }
                // Mark all multiples as visited.
                int j = i;
                while(j < visited.size()){
                    visited[j] = true;
                    j += i;
                }
            }
        }
        return primes;
    }
};

int main(){
    Solution solution;
    vector<int> answer = solution.closestPrimes(19, 31);
    cout << "Answer: " << endl;
    printVector(answer);
}