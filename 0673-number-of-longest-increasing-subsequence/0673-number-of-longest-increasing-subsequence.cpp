class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        int maxi=-1;
        vector<int>dp(n,1);
        vector<int>count(n,1);

        for(int ind=0;ind<n;ind++){
            for(int prev=0;prev<ind;prev++){
                if( nums[ind]>nums[prev] &&  dp[ind]<1+ dp[prev] ){
                    dp[ind]=1+ dp[prev];
                    count[ind]=count[prev];
                }
                else if(nums[ind]>nums[prev] && dp[ind]==1+ dp[prev]){
                     count[ind]+= count[prev];
                }
            }
            maxi=max(maxi,dp[ind]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(dp[i]==maxi)
                ans+=count[i];
        }
        return ans;
    }
};