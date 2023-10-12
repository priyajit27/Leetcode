class Solution {
public:
    int rec(int n,vector<int>dp){
        if(n<=2)return n;
        if(dp[n]!=-1)return dp[n];
        return dp[n]=rec(n-1,dp)+rec(n-2,dp);
    }
    int climbStairs(int n) {
        // vector<int>dp(n+1,-1);
        //  return rec(n,dp);
        
        int prev=1;
        int prev1=1;
        for(int i=2;i<=n;i++){
            int sum=prev1+prev;
            prev1=prev;
            prev=sum;
        }
        return prev;
    }
};