#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<queue>

class Twitter {
private:
    int time;
    std::unordered_map<int, std::vector<std::pair<int, int>>> tweetMap; // Maps a userId -> {time of tweet, tweetID}
    std::unordered_map<int, std::unordered_set<int>> followMap; // Maps userId -> {people this person follows}

public:
    Twitter() {
        int time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        time++;
        tweetMap[userId].push_back({time, tweetId});
    }
    
    std::vector<int> getNewsFeed(int userId) {
        std::vector<int> recentTweets;
        // Add the user to their follow list.
        followMap[userId].insert(userId);

        std::priority_queue<std::vector<int>, std::vector<std::vector<int>>> tweetsHeap; // Will store time, tweetId, followeeId, index

        // Iterate over followers and add there last tweet to the hashMap.
        for (auto followee = followMap[userId].begin(); followee != followMap[userId].end(); ++followee){
            if(tweetMap[*followee].size() > 0){
                int followeeId = *followee;
                int index = tweetMap[followeeId].size()-1;
                int time = tweetMap[followeeId][index].first;
                int tweetId = tweetMap[followeeId][index].second;
                std::vector<int> toStore = {time, tweetId, followeeId, index};
                tweetsHeap.emplace(toStore);
            }
        }
        while(!tweetsHeap.empty() && recentTweets.size() < 10){
            auto mostRecent = tweetsHeap.top(); tweetsHeap.pop();
            recentTweets.push_back(mostRecent[1]);
            if (mostRecent[3] > 0){
                int prevIndex = mostRecent[3] - 1;
                auto prevTweet = tweetMap[mostRecent[2]][prevIndex];
                std::vector<int> toStore= {prevTweet.first, prevTweet.second, mostRecent[2], prevIndex};
                tweetsHeap.emplace(toStore);
            }
        }
        return recentTweets;
    }
    
    void follow(int followerId, int followeeId) {
        followMap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followMap[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */

// ["Twitter", "postTweet", "getNewsFeed", "follow", "postTweet", "getNewsFeed", "unfollow", "getNewsFeed"]
// [[], [1, 5], [1], [1, 2], [2, 6], [1], [1, 2], [1]]
int main(){
    Twitter* obj = new Twitter();
    obj->postTweet(1, 5);
    std::vector<int> tweets = obj->getNewsFeed(1);
    for(int tweet : tweets){
        std::cout << "First 1: " << tweet << std::endl;
    }
    obj->follow(1,2);
    obj->follow(1,5);
    obj->postTweet(2,6);
    std::vector<int> tweets2 = obj->getNewsFeed(1);
    for(int tweet : tweets2){
        std::cout << "Second 1: " << tweet << std::endl;
    }
    // obj->postTweet(1,8);
    // obj->postTweet(1,7);
    // std::vector<int> tweets = obj->getNewsFeed(1);
    // for(int tweet : tweets){
    //     std::cout << "Tw: " << tweet << std::endl;
    // }
}