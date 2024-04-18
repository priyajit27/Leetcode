class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        for(int i=0;i<n;i++){
            // int add=4;
            for(int j=0;j<m;j++){
                int add=4;
                if(grid[i][j]==1){
                     if(i>0) {if(grid[i-1][j]==1)add--;}
                if(i<n-1){if(grid[i+1][j]==1)add--;}
                 if(j>0) { if(grid[i][j-1]==1)add--;}
                if(j<m-1){if(grid[i][j+1]==1)add--;}
                    
                         cout<<add<<" ";
            ans+=add;
                add=0;
                }
            }
            // cout<<add<<" ";
            // ans+=add;
        }
        return ans;
    }
}; 