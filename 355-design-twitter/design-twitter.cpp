class Twitter {
public:
    unordered_map<int, unordered_set<int>> mp; 
    unordered_map<int, vector<pair<int, int>>> userTweets; 
    int curr=0;
    
    Twitter() {
        mp.clear();
        userTweets.clear();
        curr = 0;
    }

    void postTweet(int userId, int tweetId) {
        userTweets[userId].push_back({curr++, tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>> pq; 

        for (auto& tweet : userTweets[userId]) {
            pq.push(tweet);
        }

        for (int followeeId : mp[userId]) {
            for (auto& tweet : userTweets[followeeId]) {
                pq.push(tweet);
            }
        }

        vector<int> ans;
        int count = 0;
        while (!pq.empty() && count < 10) {
            ans.push_back(pq.top().second);
            pq.pop();
            count++;
        }

        return ans;
    }

    void follow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            mp[followerId].insert(followeeId);
        }
    }

    void unfollow(int followerId, int followeeId) {
        mp[followerId].erase(followeeId);
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