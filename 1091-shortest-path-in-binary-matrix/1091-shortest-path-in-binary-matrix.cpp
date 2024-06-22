class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
           int n=grid.size();int m=grid[0].size();
           queue<pair<int,pair<int,int>>> q;
        
        if(grid[0][0]==1 || grid[n-1][m-1]==-1)return -1;
        
        vector<vector<int>>dist(n,vector<int>(m,1e8));
        dist[0][0]=1;
        q.push({0,{0,0}});
        int dr[]={-1,0,0,1,1,-1,-1,1};
        int dc[]={0,1,-1,0,1,-1,1,-1};
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int node=it.first;
            int r=it.second.first;
            int c=it.second.second;
           
            for(int i=0;i<8;i++){
                int newr=dr[i]+r;
                int newc=dc[i]+c;
                if(newr>=0 && newr<n && newc>=0 && newc<n && grid[newr][newc]==0 ){
                    if(dist[r][c]+1<dist[newr][newc]){
                        dist[newr][newc]=dist[r][c]+1;
                        q.push({dist[r][c]+1,{newr,newc}});
                    }
                }
            }
        }
        if(dist[n-1][m-1]==1e8)return -1;
        return dist[n-1][m-1];
    }
};