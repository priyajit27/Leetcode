class Solution {
public:
    bool canPartition(vector<int>& nums) {
          int n=nums.size();
        // if(n==1)return false;
        int sum=0;
        for(auto i:nums)
            sum+=i;
        if(sum%2)return false;
          vector<vector<bool>>dp(n,vector<bool>(sum/2+1,false));
        for(int i=0;i<n;i++)dp[i][0]=true;
        if(sum/2>=nums[0])
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