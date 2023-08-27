class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n=stones.size();
       map<int,set<int>>mp;
        for(int i=0;i<n;i++){
            mp[stones[i]]={};
        }
        mp[stones[0]]={1};
          for(int i=0;i<n;i++){
            int curr=stones[i];
             set<int>s=mp[curr];
              for(auto jump:s){
                  int pos=curr+jump;
                  if(pos==stones[n-1])return true;
                  if(mp.find(pos)!=mp.end()){
                      mp[pos].insert(jump+1);
                      mp[pos].insert(jump);
                      if(jump-1>0)
                         mp[pos].insert(jump-1);
                  }   
              }
        }
        
        return false;
    }
};