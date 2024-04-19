class Solution {
public:
     void dfs(int i,int j,vector<vector<char>>& grid){
       if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() )
           return;
    if(grid[i][j]=='2' || grid[i][j]=='0')return;
    grid[i][j]='2';
            dfs(i+1,j,grid);
            dfs(i,j-1,grid);
            dfs(i,j+1,grid);
            dfs(i-1,j,grid);
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