class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
       int n=heights.size();
        int m=heights[0].size();
           // in the form {difference,{cell coordinates pair}}.
         priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,greater<pair<int, pair<int, int>>>>
            pq;
        
        vector<vector<int>>dist(n,vector<int>(m,1e8));
        dist[0][0]=0;
        
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        
        pq.push({0,{0,0}});
        int  diff;
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            diff=it.first;
            int r=it.second.first;
            int c=it.second.second;
            
            // if(r==n-1 && c==m-1)
            // return diff;
            
            for(int i=0;i<4;i++){
                int newr=r+dr[i];
                int newc=c+dc[i];
                if(newr>=0 && newr<n && newc>=0 && newc<m){
                   int neweffort=max(abs(heights[r][c]-heights[newr][newc]),diff);
                   if(neweffort<dist[newr][newc]){
                       dist[newr][newc]=neweffort;
                       pq.push({neweffort,{newr,newc}});
                   }
                }
            }
        }
        return dist[n-1][m-1];  
    }
};