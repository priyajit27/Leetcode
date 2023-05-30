//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
   int rec(int wt[],int val[],int i,int w, vector<vector<int>>& dp){
         if(i==0){
            return ((int)(w/wt[0]))*val[0];
        }
        if(dp[i][w]!=-1)
        return dp[i][w];
        
        int nottake=rec(wt,val,i-1,w,dp);
        
        int taken=INT_MIN;
        if(wt[i]<=w)
        taken=val[i]+rec(wt,val,i,w-wt[i],dp);
        return dp[i][w]=max(taken,nottake);
}
    int knapSack(int n, int W, int val[], int wt[]){
        //   vector<vector<int>> dp(n,vector<int>(W+1,-1));
        //   return rec(wt,val,n-1,W,dp);
        
        
        // Tabulation
        //  vector<vector<int>> dp(n,vector<int>(W+1,0));
         
        //  for(int i=0;i<=W;i++)
        //  dp[0][i]=((int)(i/wt[0]))*val[0];
        //  for(int i=1;i<n;i++){
        //      for(int j=0;j<=W;j++){
        //           int nottake=dp[i-1][j];
        //       int taken=INT_MIN;
        //         if(wt[i]<=j)
        //         taken=val[i]+dp[i][j-wt[i]];
        //   dp[i][j]=max(taken,nottake);
        //      }
        //  }
        //  return dp[n-1][W];
        
        // Space optimised
         vector<int>prev(W+1,0);
        //  vector<int>curr(W+1,0);
         for(int i=0;i<=W;i++)
         prev[i]=((int)(i/wt[0]))*val[0];
         for(int i=1;i<n;i++){
                vector<int>curr(W+1,0);
             for(int j=0;j<=W;j++){
                  int nottake=prev[j];
              int taken=INT_MIN;
                if(wt[i]<=j)
                taken=val[i]+curr[j-wt[i]];
          curr[j]=max(taken,nottake);
             }
             prev=curr;
         }
         return prev[W];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends