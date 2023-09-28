// https://leetcode.com/problems/design-twitter/description/

class Twitter {
public:
    int time;
    unordered_map<int, unordered_set<int>> userFolloweeMap;
    unordered_map<int, list<pair<int, int>>> userTweetMap;

    Twitter():time(0){
        
    }
    
    void postTweet(int userId, int tweetId) {
        time++;
        auto it = userTweetMap.find(userId);
        if(it == userTweetMap.end()) {
            list<pair<int, int>> tweetList;
            tweetList.push_front(make_pair(time, tweetId));
            userTweetMap[userId] = tweetList;
        } else {
            it->second.push_front(make_pair(time, tweetId));
        }
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> result;
        priority_queue<pair<int, int>> tweetPQ;

        auto it = userFolloweeMap.find(userId);
        if(it != userFolloweeMap.end()) {
            for(auto &user : it->second) {
               // get the tweets from the user tweet map
               list<pair<int, int>> tweetList = userTweetMap[user];
               int maxTweets = 0;
               for(auto &tweet : tweetList) {
                   if(++maxTweets > 10) {
                       break;
                   } else {
                       tweetPQ.push(tweet);
                   }
               }
            }
        } else {
            list<pair<int, int>> tweetList = userTweetMap[userId];
            for(auto &tweet : tweetList) {
                tweetPQ.push(tweet);
            }
        }

        while(tweetPQ.size()) {
            result.emplace_back(tweetPQ.top().second);
            tweetPQ.pop();

            if(result.size() >= 10) {
                return result;
            }
        }

        return result;
    }
    
    void follow(int followerId, int followeeId) {
        auto it = userFolloweeMap.find(followerId);
        if(it == userFolloweeMap.end()) {
            unordered_set<int> followeeSet;

            followeeSet.insert(followerId);
            followeeSet.insert(followeeId);
            userFolloweeMap[followerId] = followeeSet;   
        } else {
            it->second.insert(followeeId);
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        auto it = userFolloweeMap.find(followerId);
        if(it != userFolloweeMap.end()) {
           it->second.erase(followeeId);  
        } 
    }
};
