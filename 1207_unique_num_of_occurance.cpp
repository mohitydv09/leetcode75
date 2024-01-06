#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        // Sort the array.
        sort(arr.begin(),arr.end());

        // Create a array of number of occurance.
        vector<int> count_arr;
        int count = 1;
        for (int i = 1; i < arr.size(); i++){
            if (arr[i] == arr[i-1]){
                count ++;
            }else{
                count_arr.push_back(count);
                count = 1; 
            }
        }
        count_arr.push_back(count);

        // Sort the count array.
        sort(count_arr.begin(), count_arr.end());
        for (int i = 1; i < count_arr.size(); i++){
            if (count_arr[i] == count_arr[i-1]){
                // Repeat element found return false.
                return false;
            }
        }
        return true;
    }
};

int main(){
    Solution solution_instance;
    vector<int> arr = {1,2,2,1,1,3};
    cout << solution_instance.uniqueOccurrences(arr);
    return 0;
} 