class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
//     similar like LIS
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int>dp(n,1);
        vector<int>hash(n,0);
        for(int ind=0;ind<n;ind++){
            hash[ind]=ind;
            for(int prev=0;prev<ind;prev++){
                if( nums[ind]%nums[prev]==0 && 1+ dp[prev]>dp[ind]){
                    dp[ind]=1+ dp[prev];
                    hash[ind]=prev;
                }
            }
        }
        
        int ans=-1;
        int lastindex=-1;
        for(int i=0;i<n;i++){
            if(dp[i]>ans){
                ans=dp[i];
                 lastindex=i;
            }
        }
        vector<int>v;
        v.push_back(nums[lastindex]);
        while(hash[lastindex]!=lastindex){
            lastindex=hash[lastindex];
             v.push_back(nums[lastindex]);
        }
        reverse(v.begin(),v.end());
        return v;
    }
};