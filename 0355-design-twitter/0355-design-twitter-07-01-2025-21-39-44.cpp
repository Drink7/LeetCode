class Twitter {
public:
    Twitter() {
        // unordered_map<int, vector<int>> followerMap;
        // unordered_map<int, vector<pair<int, int>>> tweetMap;
    }
    
    void postTweet(int userId, int tweetId) {
        tweetTime++;
        tweetMap[userId].push_back({tweetTime, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        unordered_set<int> followee = followerMap[userId];
        vector<int> followeeArr(followee.begin(), followee.end());
        vector<int> result;
        int count = 10;
        priority_queue<pair<int, int>> pq;

        for (auto const& news : tweetMap[userId]) {
            pq.push(news);
        }

        for (int i = 0; i < followeeArr.size(); i++) {
            int followeeId = followeeArr[i];
            for (auto const& news : tweetMap[followeeId]) {
                pq.push(news);
            }
        }

        int pqSize = pq.size();
        count = min(count, pqSize);
        for (int i = 0; i < count; i++) {
            pair<int, int> latestTweet = pq.top();
            result.push_back(latestTweet.second);
            pq.pop();
        }
        return result;
    }
    
    void follow(int followerId, int followeeId) {
        followerMap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followerMap[followerId].erase(followeeId);
    }
private:
    unordered_map<int, unordered_set<int>> followerMap;
    unordered_map<int, vector<pair<int, int>>> tweetMap;
    int tweetTime = 0;
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */