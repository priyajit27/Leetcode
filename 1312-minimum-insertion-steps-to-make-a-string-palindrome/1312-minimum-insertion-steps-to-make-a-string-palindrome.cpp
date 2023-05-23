class Solution {
public:
     // Longest palindromic subsequence idea using
     int longestPalindromeSubseq(string s) {
        string s1=s;
        reverse(s.begin(),s.end());
       int n=s1.length();
        int m=s.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1));
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0 || j==0)
                    dp[i][j]=0;
            }
        }
         for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1] == s[j-1])
                    dp[i][j]=1+dp[i-1][j-1];
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]) ;
            }
        }
        
        return dp[n][m]; 
    }
    int minInsertions(string s) {
        int n=s.length();
        int length=longestPalindromeSubseq(s) ;
        return n-length;
        
    }
};