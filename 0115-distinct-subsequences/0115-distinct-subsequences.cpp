class Solution {
public:
    int p=1e9+7;
    int rec(int i,int j,string s1,string s2, vector<vector<int>>& dp){
        if(i<0)
            return 0;
        if(j<0)
            return 1;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(s1[i]==s2[j]){
           int stay=rec(i-1,j-1,s1,s2,dp);
            int leaveone=rec(i-1,j,s1,s2,dp);
            return dp[i][j]= (stay+leaveone)%p;
        }
        else
            return dp[i][j]= rec(i-1,j,s1,s2,dp);
    }
    int numDistinct(string s1, string s2) {
        int n=s1.length();
        int m=s2.length();
        // vector<vector<int>>dp(n,vector<int>(m,-1));
        // return rec(n-1,m-1,s1,s2,dp);
        
//         Tabulation like LCS index shifting
         vector<vector<double>>dp(n+1,vector<double>(m+1,0));
        
        for(int i=0;i<n+1;i++)
            dp[i][0]=1;
//          for(int j=1;j<m+1;j++)
//             dp[0][j]=0;
        
        for(int i=1;i<=n;i++){
          for(int j=1;j<=m;j++){
             if(s1[i-1]==s2[j-1]){
           int stay=dp[i-1][j-1];
            int leaveone=dp[i-1][j];
             dp[i][j]= (stay+leaveone)%p;
             }
              else
              dp[i][j]= dp[i-1][j];   
        }  
        }
         return (int)dp[n][m];
    }
};