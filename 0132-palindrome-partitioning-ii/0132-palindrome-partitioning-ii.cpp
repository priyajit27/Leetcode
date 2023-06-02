class Solution {
public:
    bool isPlaindrome(string &s){
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]!=s[n-1-i])
                return false;
        }
        return true;
    }
    int rec(int i,string &s,vector<int>& dp){
        int n=s.size();
        if(i==n)
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        string temp;
        int mincost=INT_MAX;
        for(int j=i;j<n;j++){
            temp+=s[j];
            if(isPlaindrome(temp)){
                 int cost=1+rec(j+1,s,dp);
                mincost=min(mincost,cost);
            }
        }
        return dp[i]= mincost;
    }
    int minCut(string s) {
        int n=s.size();
        vector<int>dp(n,-1);
        return rec(0,s,dp)-1;
    }
};