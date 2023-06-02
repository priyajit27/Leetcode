class Solution {
public:
     int rec(int i,vector<int>& arr,vector<int>& dp,int k){
        int n=arr.size();
        if(i==n)
            return 0;
        if(dp[i]!=-1)
            return dp[i];
         
         int len=0;
         int maxi=INT_MIN;
         int maxsum=INT_MIN;
        for(int j=i;j<min(n,i+k);j++){
          len++;
           maxi=max(maxi,arr[j]) ;
          int sum=len*maxi+rec(j+1,arr,dp,k);
            maxsum=max(maxsum,sum);   
        }
        return dp[i]= maxsum;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
         vector<int>dp(n,-1);
        return rec(0,arr,dp,k);
    }
};