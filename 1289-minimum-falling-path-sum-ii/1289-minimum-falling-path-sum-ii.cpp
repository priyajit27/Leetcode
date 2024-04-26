class Solution {
public:
     int rec(int i,int j,vector<vector<int>>& matrix,vector<vector<int>>& dp){
    if(i<0 || j<0 || j>=matrix.size())
    return 1e8;
   
    if(dp[i][j]!=-1)
    return dp[i][j];
         
   if(i==0)return matrix[0][j];
        int minm=1e8;
   for(int k=0;k<matrix.size();k++){
       if(k!=j)
       minm=min(minm,matrix[i][j]+rec(i-1,k,matrix,dp));
   }
    return dp[i][j]=minm;
         // return dp[i][j];
}
    int minFallingPathSum(vector<vector<int>>& matrix) {
          int n=matrix.size();
        // int m=matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        int ans=1e5;
        for(int j=0;j<n;j++){
            ans=min(ans,rec(n-1,j,matrix,dp));
        }
        return ans;
    }
};