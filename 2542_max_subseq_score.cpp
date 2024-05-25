#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    struct idxwithScore{
        int idx;
        int score;
        idxwithScore(int idx, int score) : idx(idx), score(score) {}
    };

    struct Compare{
        bool operator()(const idxwithScore& a, const idxwithScore& b){
            return a.score < b.score;
        }
    };

    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<idxwithScore, vector<idxwithScore>, Compare> pq;
        for (int i = 0; i < nums2.size(); i++){
            idxwithScore item = {i, nums2[i]};
            pq.push(item);
        }
        idxwithScore a = pq.top();

        vector<int> idxs(k);
        for (int i = 0; i < k; i++){
            idxwithScore item = pq.top();
            idxs[i] = item.idx;
            pq.pop();
        }

        cout << "Size of idxs : " << idxs.size() << endl;

        long long max_score = 0;
        long long running_sum = 0
        for(int i = 0; i < nums2.size()-k; i++){
            long long currSum = 0;
            for(int j = 0; j < k; j++){
                idxwithScore item = pq.top();
                currSum += nums1[item.idx];
                if(j == k-1){
                    long long minNums2 = nums2[item.idx];
                }
                pq.pop();
                
            }
            long long curr_score = minNums2 * currSum;
            if (curr_score > max_score){
                max_score = curr_score;
            }
        }
        return max_score;
    }
};

int main(){
    Solution solution_instance;
    vector<int> input1 = {1,3,3,2};
    vector<int> input2 = {2,1,3,4};
    int k = 3;
    cout << "Answer : " << solution_instance.maxScore(input1, input2, k) << endl;
    return 0;
}