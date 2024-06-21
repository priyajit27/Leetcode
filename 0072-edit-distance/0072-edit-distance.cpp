class Solution {
public:
    int rec(string s1,string s2,int i,int j, vector<vector<int>>& dp){
        if(i<0)
            return j+1;
        if(j<0)
            return i+1;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(s1[i]==s2[j])
            return dp[i][j]= 0+rec(s1,s2,i-1,j-1,dp);
        return 1+min(rec(s1,s2,i-1,j-1,dp),min(rec(s1,s2,i-1,j,dp),rec(s1,s2,i,j-1,dp)));
    }
    int minDistance(string word1, string word2) {
        int n=word1.length();
        int m=word2.length();
//          vector<vector<int>>dp(n,vector<int>(m,-1));      
//          return rec(word1,word2,n-1,m-1,dp);
        
        
        // tabulation
          vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int j=0;j<=m;j++){
            dp[0][j]=j;
        }
          for(int i=0;i<=n;i++){
            dp[i][0]=i;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(word1[i-1]==word2[j-1])
                    dp[i][j]=dp[i-1][j-1];
                else
                   dp[i][j] =1+min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
            }
        }
        return dp[n][m];
        
        
//          vector<int>curr(m+1,0);       
//          vector<int>prev(m+1,0);
//         for(int j=0;j<=m;j++){
//             prev[j]=j;
//         }
//         for(int i=1;i<=n;i++){
//             curr[0]=i;
//             for(int j=1;j<=m;j++){
//                 if(word1[i-1]==word2[j-1])
//                     curr[j]=prev[j-1];
//                 else
//                    curr[j] =1+min(prev[j-1],min(prev[j],curr[j-1]));
//             }
//             prev=curr;
//         }
//         return prev[m];
    }
};