class Solution {
public:
     int rec(vector<int>& prices,int index,int buy,vector<vector<vector<int>>>& dp,int cap){
        int n=prices.size();
        if(index==n || cap==0)
            return 0;
         if(dp[index][buy][cap]!=-1)
        return dp[index][buy][cap];
        int profit;
        if(buy==0)
         profit=max(-prices[index]+rec(prices,index+1,1,dp,cap),rec(prices,index+1,0,dp,cap));
            
            else
            profit=max(prices[index]+rec(prices,index+1,0,dp,cap-1),rec(prices,index+1,1,dp,cap))  ;  
        return dp[index][buy][cap]= profit;
    }
    int maxProfit(vector<int>& prices) {
         int n=prices.size();
          vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return rec(prices,0,0,dp,2);
        
//         Tabulation
//         dp[n][0]=0;     
//         dp[n][1]=0;
        
//         int profit;
//         for(int index=n-1;index>=0;index--){
//             for(int buy=0;buy<=1;buy++){
//                  if(buy==0)
//          profit=max(-prices[index]+dp[index+1][1],dp[index+1][0]);
            
//             else
//             profit=max(prices[index]+dp[index+1][0],dp[index+1][1])  ;  
//            dp[index][buy]= profit;
//             }
//         }
//         return dp[0][0];
        
//         vector<int>curr(2,0);
//          vector<int>ahead(2,0);

//            ahead[0]=0;     
//         ahead[1]=0;
        
//         int profit;
//         for(int index=n-1;index>=0;index--){
//             for(int buy=0;buy<=1;buy++){
//                  if(buy==0)
//          profit=max(-prices[index]+ahead[1],ahead[0]);
            
//             else
//             profit=max(prices[index]+ahead[0],ahead[1])  ;  
//            curr[buy]= profit;
//             }
//             ahead=curr;
//         }
//         return ahead[0]; 
    }
};