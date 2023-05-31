class Solution {
public:
    int rec(int i,int prev,vector<int>& nums, vector<vector<int>>& dp){
        int n=nums.size();
        if(i==n)
            return 0;
        if(dp[i][prev+1]!=-1)
            return dp[i][prev+1];
//         not pick
        int nottake=rec(i+1,prev,nums,dp);
//         pick
        int take=0;
       if(prev==-1 || nums[i]>nums[prev]) 
        take=1+rec(i+1,i,nums,dp);
        
        return dp[i][prev+1]= max(take,nottake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        // vector<vector<int>>dp(n,vector<int>(n+1,-1));
        // return rec(0,-1,nums,dp);
        
//      vector<vector<int>>dp(n+1,vector<int>(n+1,0));
//         for(int i=n-1;i>=0;i--){
//             for(int j=i-1;j>=-1;j--){
//                  int nottake=dp[i+1][j+1];
//         //         pick
//         int take=0;
//        if(j==-1 || nums[i]>nums[j]) 
//         take=1+dp[i+1][i+1];
        
//         dp[i][j+1]= max(take,nottake);
//             }
//         }
//        return dp[0][0];
        
         vector<int>front(n+1,0);
                 vector<int>curr(n+1,0);

        for(int i=n-1;i>=0;i--){
            for(int j=i-1;j>=-1;j--){
                 int nottake=front[j+1];
        //         pick
        int take=0;
       if(j==-1 || nums[i]>nums[j]) 
        take=1+front[i+1];
        
        curr[j+1]= max(take,nottake);
            }
            front=curr;
        }
       return front[0];
    }
};