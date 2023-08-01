class Solution {
public:
    bool sum1(int target,vector<int>& nums,int i,vector<vector<int>>& dp){
        if(target==0)return true;
        if(i==0)return target==nums[0];
        if(dp[i][target]!=-1)return dp[i][target];
        bool nottake=sum1(target,nums,i-1,dp);
        bool take = false;
        if(target>=nums[i])
            take=sum1(target-nums[i],nums,i-1,dp);
        return dp[i][target]= take || nottake;
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(auto i:nums)
            sum+=i;
        if(sum%2)return false;
        
         // vector<vector<int>>dp(n,vector<int>(sum+1,-1));
         // return sum1(sum/2,nums,n-1,dp);
         vector<vector<bool>>dp(n,vector<bool>(sum+1,false));
        for(int i=0;i<n;i++)dp[i][0]=true;
        dp[0][nums[0]]=true;
        for(int i=1;i<n;i++){
        for(int target=1;target<=sum/2;target++){
        bool nottake=dp[i-1][target];
        bool take = false;
        if(target>=nums[i])
            take=dp[i-1][target-nums[i]];
         dp[i][target]= take || nottake; 
            }
        }
        return dp[n-1][sum/2];
    }
};