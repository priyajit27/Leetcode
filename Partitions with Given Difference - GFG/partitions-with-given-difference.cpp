//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  int findWaysUtil(int ind, int target,vector<int>& arr, vector<vector<int>> &dp){
    
    int m=1e9+7;
    if(ind == 0){
        if(target==0 && arr[0]==0)return 2;
        if(target==0 || arr[0]==target)return 1;
        return 0;
    }
        
    
    if(dp[ind][target]!=-1)
        return dp[ind][target];
        
    int notTaken = findWaysUtil(ind-1,target,arr,dp);
    
    int taken = 0;
    if(arr[ind]<=target)
        taken = findWaysUtil(ind-1,target-arr[ind],arr,dp);
        
    return dp[ind][target]= (notTaken + taken)%m;
}
    int countPartitions(int n, int d, vector<int>& arr) {
            int m=1e9+7;
        int total=0;
        for(int i=0;i<n;i++)
        total+=arr[i];
        int s2=(total-d);
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
        
               curr[j]= (notTaken + taken)%m;
            }
            prev=curr;
        }
        return prev[s2/2];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends