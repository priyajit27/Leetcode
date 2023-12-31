class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int n=s.length();
        map<char,int>mp;
        int maxm=-1;
        for(int i=0;i<n;i++){
            if(mp.find(s[i])==mp.end())
                mp[s[i]]=i;
            else{
                int start=mp[s[i]];
                int end=i;
                maxm=max(maxm,end-start-1);
            }
        }
        return maxm;
    }
};