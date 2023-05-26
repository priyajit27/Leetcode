class Solution {
public:
//     Dijkstra's Algo  with directed edges
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
          vector<pair<int,int>>adj[n+1];
        for(auto i:times)
            adj[i[0]].push_back({i[1],i[2]});
        
         priority_queue< pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>> > pq;
        pq.push({0,k});
        vector<int>dist(n+1,1e8);
        dist[0]=0;
        dist[k]=0;
        while(!pq.empty()){
           auto it=pq.top() ;
            pq.pop();
            int dis=it.first;
            int node=it.second;
            
            for(auto i:adj[node]){
                int adjnode=i.first;
                int d=i.second;
                if(d+dis<dist[adjnode]){
                    dist[adjnode]=d+dis;
                    pq.push({d+dis,adjnode});
                }
            }
        }
        int ans=-1;
        for(int i=1;i<=n;i++){
           if(dist[i]==1e8) return -1;
            ans=max(ans,dist[i]) ;
        }
        return ans;
    }
};