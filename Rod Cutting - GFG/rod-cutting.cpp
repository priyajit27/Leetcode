//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
   int rec(int cuts[],int i,int n, vector<vector<int>>& dp){
         if(i==0){
            return n*cuts[0];
        }
        if(dp[i][n]!=-1)
        return dp[i][n];
        
        int nottake=rec(cuts,i-1,n,dp);
        
        int taken=INT_MIN;
        int rodlength=i+1;
        if(rodlength<=n)
        taken=cuts[i]+rec(cuts,i,n-rodlength,dp);
        return dp[i][n]=max(taken,nottake);
}
    int cutRod(int cuts[], int n) {
        //      vector<vector<int>> dp(n,vector<int>(n+1,-1));
        //   return rec(cuts,n-1,n,dp);
        
        
          // Tabulation
        //  vector<vector<int>> dp(n,vector<int>(n+1,0));
         
        //  for(int i=0;i<=n;i++)
        //  dp[0][i]=i* cuts[0];
        //  for(int i=1;i<n;i++){
        //      for(int j=0;j<=n;j++){
        //           int nottake=dp[i-1][j];
        //       int taken=INT_MIN;
        //       int rodlength=i+1;
        //         if(rodlength<=j)
        //         taken=cuts[i]+dp[i][j-rodlength];
        //   dp[i][j]=max(taken,nottake);
        //      }
        //  }
        //  return dp[n-1][n];
        
        
           // Space optimised\
         vector<vector<int>> dp(n,vector<int>(n+1,0));
         
           vector<int>prev(n+1,0);
         vector<int>curr(n+1,0);
         for(int i=0;i<=n;i++)
         prev[i]=i* cuts[0];
         for(int i=1;i<n;i++){
             for(int j=0;j<=n;j++){
                  int nottake=prev[j];
              int taken=INT_MIN;
              int rodlength=i+1;
                if(rodlength<=j)
                taken=cuts[i]+curr[j-rodlength];
          curr[j]=max(taken,nottake);
             }
             prev=curr;
         }
         return prev[n];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends