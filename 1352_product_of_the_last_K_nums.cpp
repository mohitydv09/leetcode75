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

class ProductOfNumbers {
    private:
        vector<int> nums = {1}; // Container to hold the prefix sums
        int lastZeroIdx = 0;

    public:
        ProductOfNumbers() {}
        
        void add(int num) {
            if(num == 0){
                nums.push_back(1);
                lastZeroIdx = nums.size()-1;
            }else{
                nums.push_back(num*nums[nums.size()-1]);
            }
        }
        
        int getProduct(int k) {
            if(nums.size() - k <= lastZeroIdx){
                return 0;
            }else{
                return nums[nums.size()-1] / nums[nums.size()-2];
            }
        }
    };
    
    /**
     * Your ProductOfNumbers object will be instantiated and called as such:
     * ProductOfNumbers* obj = new ProductOfNumbers();
     * obj->add(num);
     * int param_2 = obj->getProduct(k);
     */

int main(){
    ProductOfNumbers* obj = new ProductOfNumbers;
    obj->add(3);
    int param_2 = obj->getProduct(5);
}