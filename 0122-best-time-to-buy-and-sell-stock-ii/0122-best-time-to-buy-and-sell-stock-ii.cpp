class Solution {
public:
    int rec(vector<int>& prices,int index,int buy,  vector<vector<int>>& dp){
        int n=prices.size();
        if(index==n)
            return 0;
         if(dp[index][buy]!=-1)
        return dp[index][buy];
        int profit;
        if(buy==0)
         profit=max(-prices[index]+rec(prices,index+1,1,dp),rec(prices,index+1,0,dp));
            
            else
            profit=max(prices[index]+rec(prices,index+1,0,dp),rec(prices,index+1,1,dp))  ;  
        return dp[index][buy]= profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
          vector<vector<int>> dp(n+1,vector<int>(2,-1));
        // return rec(prices,0,0,dp);
        
//         Tabulation
        dp[n][0]=0;     
        dp[n][1]=0;
        
        int profit;
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