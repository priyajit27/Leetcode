class Solution {
public:
int rec(int i,int j,vector<vector<int>>& matrix,vector<vector<int>>& dp){
    if(j>=matrix.size() || j<0)
    return 1e5;
      if(i==0 )
    return matrix[0][j];
    if(dp[i][j]!=-1)
    return dp[i][j];
    int st=matrix[i][j]+rec(i-1,j,matrix,dp);
    int ld=matrix[i][j]+rec(i-1,j-1,matrix,dp);
    int rd=matrix[i][j]+rec(i-1,j+1,matrix,dp);
    return dp[i][j]=min(st,min(ld,rd));
}
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        // vector<vector<int>>dp(n,vector<int>(n,-1));
        int ans=1e5;
        // for(int j=0;j<n;j++){
        //     ans=min(ans,rec(n-1,j,matrix,dp));
        // }
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            dp[0][i]=matrix[0][i];
        }
        int ld,rd,st;
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                   st=matrix[i][j]+dp[i-1][j];
                // ld=matrix[i][j];
                if(j>0) ld=matrix[i][j]+dp[i-1][j-1];
                else ld+=1e5;
                // rd=matrix[i][j];
                if(j<n-1) rd=matrix[i][j]+dp[i-1][j+1];
                else rd+=1e5;
                dp[i][j]=min(st,min(ld,rd));
            }
        }
          for(int j=0;j<n;j++){
            ans=min(ans,dp[n-1][j]);
        }
        return ans;
    }
};