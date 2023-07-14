class Twitter {
public:
    map<int,map<int,int>>followlist;
    vector<pair<int,int>>post;
    Twitter() {
    }
    
    void postTweet(int userId, int tweetId) {
        post.push_back({userId,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
       vector<int>ans;
        int i=post.size()-1;
       while(i>=0){
           if(post[i].first==userId ||  followlist[userId][post[i].first]){
               ans.push_back(post[i].second);
           }
           
           if(ans.size()==10)break;
           i--;
       }
        
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        followlist[followerId][followeeId]=1;
    }
    
    void unfollow(int followerId, int followeeId) {
        followlist[followerId][followeeId]=0;
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