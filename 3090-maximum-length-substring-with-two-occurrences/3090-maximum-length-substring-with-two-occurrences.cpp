class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n=s.length();
        int ans=0;
      for(int i=0;i<n;i++){
           map<char,int>mp;
          for(int j=i;j<n;j++){
             // map<char,int>mp;
              mp[s[j]]++;
              if(mp[s[j]]>2)break;
              ans=max(ans,j-i+1);
          }
      }
        return ans;
    }
};