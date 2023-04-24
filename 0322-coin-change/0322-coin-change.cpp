class Solution {
public:
    int rec(int index,vector<int>& coins,int amount, vector<vector<int>>& dp){
        if(index==0){
            if(amount%coins[0]==0)return amount/coins[0];
            else  return 1e9;
        }
        if(dp[index][amount]!=-1)return dp[index][amount];
        int nottake=0+rec(index-1,coins,amount,dp);
        // cout<<nottake;
        int take=INT_MAX;
        if(coins[index]<=amount){
            take=1+rec(index,coins,amount-coins[index],dp);
            // cout<<take;
        }
        return dp[index][amount]=min(take,nottake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        // vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        //  int ans= rec(n-1,coins,amount,dp);
        // if(ans>=1e9)return -1;
        // else return ans;
        
        
//         Memoisation
         vector<vector<int>>dp(n,vector<int>(amount+1,0));
        for(int i=0;i<=amount;i++){
            if(i%coins[0]==0)
                dp[0][i] =i/coins[0];
            else  dp[0][i] =1e9;     
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<=amount;j++){
        int nottake=0+dp[i-1][j];
        int take=INT_MAX;
        if(coins[i]<=j)
            take=1+dp[i][j-coins[i]];
        dp[i][j]=min(take,nottake);

         }
        }
        if (dp[n-1][amount]>=1e9)return -1;
        else return dp[n-1][amount];
    }
};