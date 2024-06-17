class Solution {
public:
    int drow[4]={-1,1,0,0};
        int dcol[4]={0,0,1,-1};
    
     void dfs(int row,int col,vector<vector<char>>& grid){
    //    if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() )
    //        return;
    // if(grid[i][j]=='2' || grid[i][j]=='0')return;
    // grid[i][j]='2';
    //         dfs(i+1,j,grid);
    //         dfs(i,j-1,grid);
    //         dfs(i,j+1,grid);
    //         dfs(i-1,j,grid);
         
         grid[row][col]='2';
         int n=grid.size();   int m=grid[0].size();
          for(int i=0;i<4;i++){
                 int nrow=drow[i]+row;
                 int ncol=dcol[i]+col;
                 if(nrow>=0 && nrow<n && ncol>=0 && ncol<m &&  grid[nrow][ncol]!='0'  && grid[nrow][ncol]!='2'){
                    dfs(nrow,ncol,grid);
                 }
    }
     }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
         int count=0;
        // vector<bool>visited(n+1,false);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
            if(grid[i][j]=='1'){
                count++;
                dfs(i,j,grid);
            }
        }
        }
        return count;
    }
};