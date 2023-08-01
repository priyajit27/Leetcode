class Solution {
public:
int up=0,down=0;
int rec(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& dp){
    if(i==0 && j==0)
    return grid[i][j];
    if(i<0 || j<0)
    return 100000;
    if(dp[i][j]!=-1)
    return dp[i][j];
    int up=grid[i][j]+rec(i-1,j,grid,dp);
    int down =grid[i][j]+rec(i,j-1,grid,dp);
    return dp[i][j]= min(up,down);
}
    int minPathSum(vector<vector<int>>& grid) {
        //   Memoisation
        int m=grid.size();
        int n=grid[0].size();
      vector<vector<int>>dp(m,vector<int>(n,-1));
      int ans=rec(m-1,n-1,grid,dp);
      return ans;
    // dp[0][0]=grid[0][0];
    // for(int i=0;i<m;i++){
    //    for(int j=0;j<n;j++) {
    //        if(i==0 && j==0)
    //         continue;
    //         else{
    //           if(i>0)  up=grid[i][j]+rec(i-1,j,grid,dp);
    //           else up=grid[i][j]+1e5;
    //            if(j>0)down =grid[i][j]+rec(i,j-1,grid,dp);
    //             else down=grid[i][j]+1e5;
    //            dp[i][j]=min(up,down);
    //         }
    //    }
    // }
    // return dp[m-1][n-1];

    //  Space optimised
    // vector<int>prev(n,0);
    // for(int i=0;i<m;i++){
    //        vector<int>curr(n,0);
    //     for(int j=0;j<n;j++){
    //         if(i==0 && j==0)
    //           curr[j]=grid[0][0];
    //         else{
    //             int up=0,down=0;
    //            if(i>0)up=grid[i][j]+prev[j];
    //            else up=grid[i][j]+1e5;
    //            if(j>0)down=grid[i][j]+curr[j-1];
    //            else down=grid[i][j]+1e5;
    //            curr[j]=min(up,down);
    //         }
    //     }
    //     prev=curr;
    // }
    // return prev[n-1];
    }
};