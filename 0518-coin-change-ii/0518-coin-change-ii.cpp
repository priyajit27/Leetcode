class Solution {
public:
    int rec(int index,vector<int>& coins,int amount,vector<vector<int>>& dp){
        if(index==0){
            if(amount%coins[0]==0)
                return 1;
            else  return 0;
        }
        if(dp[index][amount]!=-1)return dp[index][amount];
        int nottake=rec(index-1,coins,amount,dp);
        int take=0;
        if(coins[index]<=amount){
            take=rec(index,coins,amount-coins[index],dp);
        }
        return dp[index][amount]=(take+nottake);
    }
    int change(int amount, vector<int>& coins) {
         int n=coins.size();
        // vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        // return rec(n-1,coins,amount,dp);
        
        //         Memoisation
         vector<vector<int>>dp(n,vector<int>(amount+1,0));
        for(int i=0;i<=amount;i++){
            if(i%coins[0]==0)
                dp[0][i] =1;
            else  dp[0][i] =0;     
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<=amount;j++){
        int nottake=dp[i-1][j];
        int take=0;
        if(coins[i]<=j)
            take=dp[i][j-coins[i]];
        dp[i][j]=(take+nottake);

         }
        }
         return dp[n-1][amount];
    }
};