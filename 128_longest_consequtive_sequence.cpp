#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int,int> hashMap;
        for(int i = 0; i < nums.size(); ++i){
            hashMap[nums[i]] = 1;
        }
        int longestSeq = 0;
        for(auto pair : hashMap){
            int seqSize = 0;
            if(!hashMap[pair.first-1]){
                cout << "Seq Start found: " << pair.first << endl;
                seqSize++;
                while(hashMap[pair.first + seqSize]){
                    cout << "Next item found: " << pair.first + seqSize << endl;
                    seqSize++;
                }
                cout << "seqSize is : " << seqSize << endl;
                if(seqSize > longestSeq){
                    longestSeq = seqSize;
                }
            }
        }

        // for(int i = 0; i < nums.size(); ++i){
        //     int seqSize = 0;
        //     if(!hashMap[nums[i]-1]){
        //         cout << "Seq Start found: " << nums[i] << endl;
        //         seqSize++;
        //         while(hashMap[nums[i] + seqSize]){
        //             cout << "Next item found: " << nums[i] + seqSize << endl;
        //             seqSize++;
        //         }
        //         cout << "seqSize is : " << seqSize << endl;
        //         if(seqSize > longestSeq){
        //             longestSeq = seqSize;
        //         }
        //     }
        // }
        return longestSeq;
    }
};

int main(){
    Solution solution;
    vector<int> nums = {0,3,7,2,5,8,4,6,0,1};
    int answer = solution.longestConsecutive(nums);
    cout << "Answer: " << answer << endl;
}