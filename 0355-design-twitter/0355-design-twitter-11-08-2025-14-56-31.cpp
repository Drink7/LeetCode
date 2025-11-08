class Twitter {
public:
    Twitter() {
        // most recent-> max heap
        // tweet id not promised time increasing
        // adjlist to make follow list unordered_map<int, unordered_set<int>> // followee, followers
        // tweet unordered_map<int, vector<int>> / user, user's tweet id
    }
    
    void postTweet(int userId, int tweetId) {
        // post tweet will made unique twet id
        tweetList[userId].push_back({timeStamp, tweetId});
        timeStamp++;
    }
    
    vector<int> getNewsFeed(int userId) {
        // priority_queue<pair<int, int>> maxHeap // timeStamp, tweetId
        // get user and its followers tweets
        // #1 get user's tweets, put into maxHeap
        // #2 get user foloower's tweets, put into maxHeap
        // #3 fetch 10 recent tweets
        // #4 return
        priority_queue<pair<int, int>> maxHeap;
        for (auto const& [time, id] : tweetList[userId]) {
            maxHeap.push({time, id});
        }

        // followers
        unordered_set<int> followers = adjList[userId];
        for (auto const& follower : followers) {
            for (auto const& [time, id] : tweetList[follower]) {
                maxHeap.push({time, id});
            }
        }

        // fetch 10 recent
        vector<int> result;
        int k = 10;
        while (k > 0 && maxHeap.size() > 0) {
            auto [time, id] = maxHeap.top(); maxHeap.pop();
            result.push_back(id);
            k--;
        }
        return result;
    }
    
    void follow(int followerId, int followeeId) {
        adjList[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        adjList[followerId].erase(followeeId);
    }
private:
    unordered_map<int, unordered_set<int>> adjList; // user, its followers
    unordered_map<int, vector<pair<int, int>>> tweetList; // user, timestamp, user's tweet id
    int timeStamp = 0;
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */