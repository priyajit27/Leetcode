class Solution {
public:
    int rec(vector<int>& nums,int target, vector<int>& dp){
        if(target<=0){
             if(target==0)return 1;
            return 0;
        }
        if(dp[target]!=-1)dp[target];
        int ans=0;
       for(int i=0;i<nums.size();i++){
          ans+= rec(nums,target-nums[i],dp);
       }
        return dp[target]=ans;
    }
    int combinationSum4(vector<int>& nums,int target) {
       //  vector<int>dp(target+1,-1);
       // return rec(nums,target,dp);
        
        vector<unsigned int>dp(target+1,0);
        dp[0]=1;
        for(int i=1;i<=target;i++){
            for(int j=0;j<nums.size();j++){
                if(i-nums[j]>=0)
               dp[i]+= dp[i-nums[j]];
            }
            // dp[i]=ans;
        }
        return dp[dp.size()-1];
    }
};