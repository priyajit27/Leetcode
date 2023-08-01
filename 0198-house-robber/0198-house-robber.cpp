class Solution {
public:
//     Recursion TLE
//     Memoisation
//     int rec(vector<int>& nums,int i,vector<int>& dp){
//         if(i<0)
//         return 0;
//         if(dp[i]!=-1)
//             return dp[i];
//         return dp[i]=max(rec(nums,i-2,dp)+nums[i],rec(nums,i-1,dp));
//     }
//     int rob(vector<int>& nums) {
//         // if( nums.size())
//          vector<int>dp(nums.size(),-1);
//        return rec(nums,nums.size()-1,dp);
    int rob(vector<int>& nums) {
        // if(nums.size()==1)
        //     return nums[0];
        // vector<int>dp(nums.size());
        //     dp[0]=nums[0];
        //     dp[1]=max(dp[0],nums[1]);
        // for(int i=2;i<nums.size();i++){
        //     dp[i]=max(dp[i-2]+nums[i],dp[i-1]);
        // }
        // return dp[nums.size()-1];
        
            if(nums.size()==1)
            return nums[0];
            int prev2=nums[0];
            int prev1=max(prev2,nums[1]);
        for(int i=2;i<nums.size();i++){
           int curr=max(prev2+nums[i],prev1);
            prev2=prev1;
            prev1=curr;
        }
        return prev1;
    }
};