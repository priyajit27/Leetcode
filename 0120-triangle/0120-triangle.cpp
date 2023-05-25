class Solution {
public:
//     Triangle base case opposite so in tabulaton also opposite
    int rec(vector<vector<int>>& triangle,int i,int j,vector<vector<int>>& dp){
        int n=triangle.size();
        if(i==n-1)
            return triangle[i][j];
        if(dp[i][j]!=-1)
            return dp[i][j];
        int down=triangle[i][j]+rec(triangle,i+1,j,dp);
        int diagonal=triangle[i][j]+rec(triangle,i+1,j+1,dp);
        return dp[i][j]=min(down,diagonal);
    }
    int minimumTotal(vector<vector<int>>& triangle){
        int n=triangle.size();
        // vector<vector<int>>dp(n,vector<int>(n,-1));
        // return rec(triangle,0,0,dp);
        
//         tabulation
//         vector<vector<int>>dp(n,vector<int>(n,0));
//          for(int j=0;j<n;j++)
//            dp[n-1][j]=triangle[n-1][j];
        
//         for(int i=n-2;i>=0;i--){
//           for(int j=i;j>=0;j--){
//              int down=triangle[i][j]+ dp[i+1][j];
//              int diagonal=triangle[i][j]+ dp[i+1][j+1];
//              dp[i][j]=min(down,diagonal);
//         }  
//         }
        
//         return dp[0][0];
   
        
//   Space optimisation      
         vector<int>curr(n,0);
                 vector<int>front(n,0);

         for(int j=0;j<n;j++)
           front[j]=triangle[n-1][j];
        
        for(int i=n-2;i>=0;i--){
          for(int j=i;j>=0;j--){
             int down=triangle[i][j]+ front[j];
             int diagonal=triangle[i][j]+ front[j+1];
             curr[j]=min(down,diagonal);
        }  
            front=curr;
        }
        
        return front[0];
    }
};