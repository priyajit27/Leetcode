//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    
    int rec(int wt[],int val[],int i,int w, vector<vector<int>>& dp){
        if(i==0){
            if(wt[0]<=w)
            return val[0];
            return 0;
        }
        if(dp[i][w]!=-1)
        return dp[i][w];
        
        int nottake=rec(wt,val,i-1,w,dp);
        
        int taken=INT_MIN;
        if(wt[i]<=w)
        taken=val[i]+rec(wt,val,i-1,w-wt[i],dp);
        return dp[i][w]=max(taken,nottake);
    }
    int knapSack(int W, int wt[], int val[], int n){ 
          vector<vector<int>> dp(n,vector<int>(W+1,-1));
          return rec(wt,val,n-1,W,dp);
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends