class Solution {
public:
int rec(int i,int j,vector<vector<int>>& dp,vector<vector<int>>& obstacleGrid){
     if(i>=0 && j>=0 && obstacleGrid[i][j]==1)
    return 0;
    if(i==0 && j==0)
    return 1;
    if(i<0 || j<0)
    return 0;
    // if(i>=0 && j>=0 && obstacleGrid[i][j]==1)
    // return 0;
    if(dp[i][j]!=-1)
    return dp[i][j];
    int up=rec(i-1,j,dp, obstacleGrid);
    int down =rec(i,j-1,dp,obstacleGrid);
    return dp[i][j]=up +down;
}
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
     // Memoisation
     int m=obstacleGrid.size();
     int n=obstacleGrid[0].size();
      vector<vector<int>>dp(m,vector<int>(n,-1));
    //   int ans=rec(m-1,n-1,dp,obstacleGrid);
    //   return ans;   
    dp[0][0]=1;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(i>=0 && j>=0 && obstacleGrid[i][j]==1)
               dp[i][j]=0;
                else if(i==0 && j==0)
             continue;
            else{
                int up=0,down=0;
               if(i>0)up=dp[i-1][j];
               if(j>0)down=dp[i][j-1];
               dp[i][j]=up+down;
            }
        }
    }
            return dp[m-1][n-1];
    }
};