#include<iostream>
#include<vector>
#include<numeric>

class Solution {
public:
    int candy(std::vector<int>& ratings) {
        int num_kids = ratings.size();
        std::vector<int> candies(num_kids, 1);
        for(int i = 1; i < num_kids; ++i){
            if(ratings[i] > ratings[i-1]){
                candies[i] = std::max(candies[i], candies[i-1] + 1);
            }
        }
        for(int i = num_kids - 2; i >= 0; --i){
            if(ratings[i] > ratings[i+1]){
                candies[i] = std::max(candies[i], candies[i+1] + 1);
            }
        }
        return std::accumulate(candies.begin(), candies.end(), 0);
    }
};

int main(){
    Solution solution;
    std::vector<int> ratings = {1,2,2};
    int answer = solution.candy(ratings);
    std::cout << "Answer: " << answer << std::endl;
}