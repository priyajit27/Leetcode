class Solution {
public:
    int maxProfit(vector<int>& prices) {
         int n=prices.size();
          vector<vector<int>> dp(n+1,vector<int>(2,0));
        // return rec(prices,0,0,dp);
        
        // Tabulation
        dp[n][0]=0;     
        dp[n][1]=0;
        
        int profit=0;
        for(int index=n-1;index>=0;index--){
            for(int buy=0;buy<=1;buy++){
                 if(buy==0)
         profit=max(-prices[index]+dp[index+1][1],dp[index+1][0]);
            
            else
            profit=max(prices[index]+dp[index+1][0],dp[index+1][1])  ;  
           dp[index][buy]= profit;
            }
        }
        return dp[0][0];
    }
};