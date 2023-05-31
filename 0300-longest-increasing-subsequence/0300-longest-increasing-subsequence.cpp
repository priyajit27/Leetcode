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
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
      return rec(0,-1,nums,dp);
    }
};