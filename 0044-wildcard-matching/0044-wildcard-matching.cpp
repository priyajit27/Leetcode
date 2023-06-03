class Solution {
public:
    int rec(int i,int j,string& s1, string& s2,vector<vector<int>>& dp){
//         Base case
        if(i<0 && j<0)
            return true;
        if(j<0 && i>=0)
        return false;
        if(j>=0 && i<0){
            for(int k=0;k<=j;k++){
                if(s2[k]!='*')
                    return false;
            }
             return true;
        }
        
         if (dp[i][j] !=-1) return dp[i][j];
        
        if(s1[i]==s2[j] || s2[j]=='?' )
            return dp[i][j]=rec(i-1,j-1,s1,s2,dp);
    
             if(s2[j]=='*')
            return dp[i][j]=rec(i-1,j,s1,s2,dp) || rec(i,j-1,s1,s2,dp);
        
        return false;   
      
    }
    
    bool isAllstars(string &s,int i){
          for(int k=1;k<=i;k++){
                if(s[k-1]!='*')
                    return false;
            }
             return true;
    }
    
    
    bool isMatch(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();
  // vector<vector<int>> dp(n,vector<int>(m,-1));
        // return rec(n-1,m-1,s1,s2,dp);
        
//     vector<vector<int>> dp(n+1,vector<int>(m+1,0));    
      
//         dp[0][0]=true;
//         for(int i=1;i<=n;i++){
//             dp[i][0]=false;
//         }
        
//          for(int j=1;j<=m;j++){
//             dp[0][j]=isAllstars(s2,j);
//         }
        
//         for(int i=1;i<=n;i++){
//             for(int j=1;j<=m;j++){
//                 if(s1[i-1]==s2[j-1] || s2[j-1]=='?' )
//              dp[i][j]=dp[i-1][j-1];
    
//             else{ 
//                 if(s2[j-1]=='*')
//              dp[i][j]=dp[i][j-1]|| dp[i-1][j];
//                  else
//                 dp[i][j]=false;     
//                  }
//             }
//         }
//          return dp[n][m];   
        
         vector<bool>curr(m+1,false);    
          vector<bool>prev(m+1,false);    
     
        prev[0]=true;
       
        
         for(int j=1;j<=m;j++){
            prev[j]=isAllstars(s2,j);
        }
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1] || s2[j-1]=='?' )
             curr[j]=prev[j-1];
    
            else{ 
                if(s2[j-1]=='*')
             curr[j]=curr[j-1]|| prev[j];
                 else
                curr[j]=false;     
                 }
            }
            prev=curr;
        }
         return prev[m];   
    }
};