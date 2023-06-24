class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        map<char,int>mp;
        int ans=0;
        int l=0;
        int r=0;
       while(r<n){
           if(mp.find(s[r])!=mp.end())
               l=max(l,mp[s[r]]+1);
           mp[s[r]]=r;
           ans=max(ans,r-l+1);
           r++;
       }
        return ans;
    }
};