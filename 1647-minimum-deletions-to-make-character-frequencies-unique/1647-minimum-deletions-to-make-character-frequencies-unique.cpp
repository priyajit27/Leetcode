class Solution {
public:
    int minDeletions(string s) {
        map<char,int>mp;
        for(auto i:s)
            mp[i]++;
        int ans=0;
         map<int,int>mp1;
        for(auto i:mp){
            int x=i.second;
            while(x>0 && mp1[x]!=0){
                ans++;
                x--;
            }
            mp1[x]++;
        }
        return ans;
    }
};