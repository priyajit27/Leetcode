class Solution {
public:
    int minSteps(string s, string t) {
        map<char,int>mp;
        for(auto i:s){
           mp[i]++;
        }
        for(auto i:t){
            if(mp.find(i)!=mp.end()){
                mp[i]--;
            }
            if(mp[i]==0)mp.erase(i);
        }
        int ans=0;
        for(auto i:mp){
            if(i.second!=0)
                ans+=i.second;
            cout<<ans;
        }
        return ans;
    }
};