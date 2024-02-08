class Solution {
public:
   
    int rec(int n,vector<int>& dp){
         int ans=n;
        if(n==0)return 0;
        // int ans=1;
        if(dp[n]!=-1)return dp[n];
        for(int j=1;j*j<=n;j++){
            ans=min(ans,rec(n-j*j,dp)+1);
        }
        return dp[n]= ans;
    }
    int numSquares(int n) {
        vector<int>dp(n+1,-1);
        return rec(n,dp);
    }
};