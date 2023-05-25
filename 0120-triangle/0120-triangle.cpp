class Solution {
public:
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
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return rec(triangle,0,0,dp);
    }
};