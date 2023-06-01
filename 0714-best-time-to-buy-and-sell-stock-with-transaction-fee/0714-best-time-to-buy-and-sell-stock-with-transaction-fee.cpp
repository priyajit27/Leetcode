class Solution {
public:
      int rec(vector<int>& prices,int index,int buy,  vector<vector<int>>& dp,int fee){
        int n=prices.size();
        if(index==n)
            return 0;
         if(dp[index][buy]!=-1)
        return dp[index][buy];
        int profit;
        if(buy==0)
         profit=max(-prices[index]+rec(prices,index+1,1,dp,fee),rec(prices,index+1,0,dp,fee));
            
            else
            profit=max(prices[index]+rec(prices,index+1,0,dp,fee),rec(prices,index+1,1,dp,fee))  ;  
        return dp[index][buy]= profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
          int n=prices.size();
          // vector<vector<int>> dp(n+1,vector<int>(2,-1));
        // return rec(prices,0,0,dp,fee);
        
//         Tabulation
//         dp[n][0]=0;     
//         dp[n][1]=0;
        
//         int profit;
//         for(int index=n-1;index>=0;index--){
//             for(int buy=0;buy<=1;buy++){
//                  if(buy==0)
//          profit=max(-prices[index]+dp[index+1][1],dp[index+1][0]);
            
//             else
//             profit=max(prices[index]+dp[index+1][0]-fee,dp[index+1][1])  ;  
//            dp[index][buy]= profit;
//             }
//         }
//         return dp[0][0];
        
        vector<int>curr(2,0);
         vector<int>ahead(2,0);

           ahead[0]=0;     
        ahead[1]=0;
        
        int profit;
        for(int index=n-1;index>=0;index--){
            for(int buy=0;buy<=1;buy++){
                 if(buy==0)
         profit=max(-prices[index]+ahead[1],ahead[0]);
            
            else
            profit=max(prices[index]+ahead[0]-fee,ahead[1])  ;  
           curr[buy]= profit;
            }
            ahead=curr;
        }
        return ahead[0];
    }
};