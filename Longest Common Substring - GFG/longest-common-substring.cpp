//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int longestCommonSubstr (string S1, string S2, int n, int m){
    //   int ans=0;
    //     vector<vector<int>>dp(n+1,vector<int>(m+1));
    //     for(int i=0;i<=n;i++){
    //         for(int j=0;j<=m;j++){
    //             if(i==0 || j==0)
    //                 dp[i][j]=0;
    //         }
    //     }
    //      for(int i=1;i<=n;i++){
    //         for(int j=1;j<=m;j++){
    //             if(S1[i-1] == S2[j-1]){
    //                   dp[i][j]=1+dp[i-1][j-1];
    //                   ans=max(ans,  dp[i][j]);
    //             }
    //             else
    //                 dp[i][j]=0;
    //         }
    //     }
        
    //     return ans;
    
      int ans=0;
        vector<int>prev(m+1,0);
         for(int i=1;i<=n;i++){
              vector<int>curr(m+1,0);
            for(int j=1;j<=m;j++){
                if(S1[i-1] == S2[j-1]){
                      curr[j]=1+prev[j-1];
                      ans=max(ans,curr[j]);
                }
                else
                    curr[j]=0;
            }
            prev=curr;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends