class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>>adj[n];
        for(auto i:flights)
            adj[i[0]].push_back({i[1],i[2]});
        
//         stop node distance
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{src,0}});
        vector<int>dist(n,1e8);
        dist[src]=0;
        while(!q.empty()){
          auto it =q.front()  ;
            q.pop();
            int stop=it.first;
            int node=it.second.first;
            int cost=it.second.second;
            if(stop>k)
                continue;
            for(auto i:adj[node]){
               int adjnode=i.first;
                int d=i.second;
                if(cost+ d <dist[adjnode] && stop<=k){
                    dist[adjnode]=cost+d;
                    q.push({stop+1,{adjnode,cost+d}});
                }
                    
      }
        }
        if(dist[dst]==1e8)
            return -1;
        return dist[dst];
    }
};