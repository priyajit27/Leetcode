//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int minCoins(int coins[], int n, int amount) 
	{ 
	   
//         Memoisation
         vector<vector<int>>dp(n,vector<int>(amount+1,0));
        for(int i=0;i<=amount;i++){
            if(i%coins[0]==0)
                dp[0][i] =i/coins[0];
            else  dp[0][i] =1e9;     
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<=amount;j++){
        int nottake=0+dp[i-1][j];
        int take=INT_MAX;
        if(coins[i]<=j)
            take=1+dp[i][j-coins[i]];
        dp[i][j]=min(take,nottake);

         }
        }
        if (dp[n-1][amount]>=1e9)return -1;
        else return dp[n-1][amount];
	} 
	  
};

//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends