class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {
          int n=grid.size() ;
        int m=grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        vector<vector<int>>dist(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    q.push({{i,j},0});
                visited[i][j]=1;
                }
            }
        }
        int drow[]={-1,1,0,0};
        int dcol[]={0,0,1,-1};
        while(!q.empty()){
            int p=q.front().first.first;
            int r=q.front().first.second;
            int steps= q.front().second;
            q.pop();
           dist[p][r]=steps;
             for(int i=0;i<4;i++){
                 int row=drow[i]+p;
                 int col=dcol[i]+r;
                 if(row>=0 && row<n && col>=0 && col<m && visited[row][col]==0 && grid[row][col]==1){
                     q.push({{row,col},steps+1});
                     visited[row][col]=1;
                 }
             }
        }
        return dist;
    }
};