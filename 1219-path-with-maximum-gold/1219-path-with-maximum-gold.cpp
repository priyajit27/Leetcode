class Solution {
public:
    int maxm=0;
    int dr[4]={-1,1,0,0};
    int dc[4]={0,0,-1,1};
    void rec(int i,int j,int n,int m,int &sum,vector<vector<int>>& grid){
        int curr=grid[i][j];
        grid[i][j]=0;sum+=curr;
        for(int k=0;k<4;k++){
           int nrow=dr[k]+i;
            int ncol=dc[k]+j;
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]!=0){
                 int temp= grid[nrow][ncol];
                sum+=temp;
                // cout<<sum<<" ";
                grid[nrow][ncol]=0;
                 maxm=max(maxm,sum);
                rec(nrow,ncol,n,m,sum,grid);
                  grid[nrow][ncol]=temp;
                sum-=temp;
            }
        }
         grid[i][j]=curr;
        sum-=curr;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int sum=0;
        for(int i=0;i<n;i++){
           for(int j=0;j<m;j++){
               rec(i,j,n,m,sum,grid);
           }
        }
        return maxm;
    }
};