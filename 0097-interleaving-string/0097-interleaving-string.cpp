class Solution {
public:
    bool rec(int i,int j,int k,string s1, string s2, string s3,vector<vector<int>>& dp){
        if(k==s3.length())return true;
        
     if(dp[i][j]!=-1)return dp[i][j];
        
        if(i==s1.length() && s2[j]!=s3[k])return false;
        
         if(j==s2.length() && s1[i]!=s3[k])return false;
        
         if(s2[j]!=s3[k] && s1[i]!=s3[k])return false;
        
        // if(dp[i][j]!=-1)return dp[i][j];
        
        if(s1[i]==s3[k] && s2[j]!=s3[k] )
            return dp[i][j]=rec(i+1,j,k+1,s1,s2,s3,dp);
        if(s2[j]==s3[k] && s1[i]!=s3[k] )
            return dp[i][j]= rec(i,j+1,k+1,s1,s2,s3,dp);
            return dp[i][j]=rec(i+1,j,k+1,s1,s2,s3,dp) || rec(i,j+1,k+1,s1,s2,s3,dp);
    }
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.length()+s2.length()!=s3.length())
            return false;
        vector<vector<int>>dp(s1.length()+1,vector<int>(s2.length()+1,-1));
        return rec(0,0,0,s1,s2,s3,dp);    
    }
};