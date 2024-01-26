class Solution {
public:
    long long mod=1e9 + 7;
    int rec( vector<vector<vector<int>>>& dp,int i,int j,int m,int n,int x){
        
        if(i<0 || i>=m || j>=n || j<0)return 1;
        
        if(x<=0)return 0;
            
        if(dp[i][j][x]!=-1)return dp[i][j][x];
        
       int left= rec(dp,i-1,j,m,n,x-1);
        int right= rec(dp,i+1,j,m,n,x-1);
        int top=rec(dp,i,j-1,m,n,x-1);
            int bottom=rec(dp,i,j+1,m,n,x-1);
        
        int total=(top%mod+right%mod+left%mod+bottom%mod)%mod;
        
        return dp[i][j][x]= total;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>>dp(55,vector<vector<int>>(55,vector<int>(55,-1)));
        return rec(dp,startRow,startColumn,m,n,maxMove);
    }
};