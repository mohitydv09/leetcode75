#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int,int>> pq_nums2;
        // Pair has built it commparator which is compare first, if equal compare second.
        for (int i = 0; i<nums1.size(); i++){
            pq_nums2.push({nums2[i], i });
        }

        long long curr_sum = 0;
        long long min_nums2 = INT_MAX;
        long long solution = 0;
        priority_queue<int, vector<int>, greater<int>> curr_num1;
        while(k--){
            auto top_item = pq_nums2.top(); pq_nums2.pop();
            min_nums2 = top_item.first;
            curr_sum += nums1[top_item.second];
            curr_num1.push(nums1[top_item.second]);
        }
        solution = curr_sum * min_nums2;

        while(!pq_nums2.empty()){
            // Remove the smallest item from curr_sum.
            curr_sum -= curr_num1.top(); curr_num1.pop();
            auto top_item = pq_nums2.top(); pq_nums2.pop();
            min_nums2 = top_item.first;
            curr_sum += nums1[top_item.second];
            solution = max(solution, curr_sum * min_nums2);
            curr_num1.push(nums1[top_item.second]);

        }
        return solution;
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