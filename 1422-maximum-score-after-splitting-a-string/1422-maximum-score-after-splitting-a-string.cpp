class Solution {
public:
    int maxScore(string s) {
       int n=s.length();
        int one= count(s.begin(),s.end(),'1');
        int ans=0;
        int z=0,o=0;
        int maxm=INT_MIN;
        for(int i=0;i<n-1;i++){
               if(s[i]=='0')z++;
               if(s[i]=='1')o++;
            maxm=max(maxm,z+one-o);
        }
        return maxm;
    }
};