class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<pair<int ,double>>adj[n];
        
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        
        vector<double>dist(n,INT_MIN);
        dist[start]=0;
        priority_queue<pair<double,int>>pq;
        pq.push({1.0,start});
        
        while(!pq.empty()){
            double d=pq.top().first;
             int node =pq.top().second;
            pq.pop();
            
            for(auto it:adj[node]){
                int adjnode=it.first;
                double prob=it.second;
                
                if(d*prob>dist[adjnode]){
                    dist[adjnode]=d*prob;
                    pq.push({d*prob,adjnode});
                }
                
            }
            
        }
        
        if(dist[end]==INT_MIN)
            return 0;
        else
            return dist[end];
        
    }
};