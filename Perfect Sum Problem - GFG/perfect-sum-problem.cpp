//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int m=1e9+7;
	 int subset(int target,int nums[],int i,vector<vector<int>>& dp){
        // if(target==0)return 1;
        if(i<0)return target==0;
        if(dp[i][target]!=-1)return dp[i][target];
        int nottake=subset(target,nums,i-1,dp);
        int take = 0;
        if(target>=nums[i])
            take=subset(target-nums[i],nums,i-1,dp);
        return dp[i][target]=( take+nottake)%m;
    }
	int perfectSum(int arr[], int n, int sum){
         vector<vector<int>> dp(n,vector<int>(sum+1,-1));
         return subset(sum,arr,n-1,dp);
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends