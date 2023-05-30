class Solution {
public:
    int findTargetSumWays(vector<int>& arr, int target) {
        // partitions-with-given-difference  see pura same
         
        int n=arr.size();
        int total=0;
        for(int i=0;i<n;i++)
        total+=arr[i];
        int s2=(total-target);
        if(s2<0 || s2%2==1)
        return 0;
        // vector<vector<int>>dp(n,vector<int>(s2/2+1,-1));
        // return findWaysUtil(n-1,s2/2,arr, dp);
        
        
        // Tabulation
        // vector<vector<int>>dp(n,vector<int>(s2/2+1,0));
        // if(arr[0]==0)
        // dp[0][0]=2;
        // else
        // dp[0][0]=1;
        
        // if(arr[0]!=0 && arr[0]<=s2/2)
        //   dp[0][arr[0]]=1;
        // for(int i=1;i<n;i++){
        //     for(int j=0;j<=s2/2;j++){
        //          int notTaken = dp[i-1][j];
        //          int taken = 0;
        //         if(arr[i]<=j)
        //       taken =dp[i-1][j-arr[i]];
        
        //       dp[i][j]= (notTaken + taken)%m;
        //     }
        // }
        // return dp[n-1][s2/2];
        
        
        // Space optimised
         vector<int>prev(s2/2+1,0);
         vector<int>curr(s2/2+1,0);
        if(arr[0]==0)
        prev[0]=2;
        else
        prev[0]=1;
        
        if(arr[0]!=0 && arr[0]<=s2/2)
           prev[arr[0]]=1;
        for(int i=1;i<n;i++){
            for(int j=0;j<=s2/2;j++){
                 int notTaken = prev[j];
                 int taken = 0;
                if(arr[i]<=j)
              taken =prev[j-arr[i]];
        
               curr[j]= (notTaken + taken);
            }
            prev=curr;
        }
        return prev[s2/2];
        
    }
};