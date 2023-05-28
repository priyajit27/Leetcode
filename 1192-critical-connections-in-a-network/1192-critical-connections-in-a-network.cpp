class Solution {
public:
    int timer=1;
    void dfs(int node,int parent, vector<int>& visited,vector<int>adj[],int time[],int low[], vector<vector<int>>& bridges){
        visited[node]=1;
        time[node]=low[node]=timer;
        timer++;
        for(auto i:adj[node]){
            if(i==parent)
                continue;
            if(visited[i]==0){
                   dfs(i,node,visited,adj,time,low,bridges);
                low[node]=min(low[node],low[i]);
                if(low[i]>time[node])
                    bridges.push_back({i,node});
            }
            else
                low[node]=min(low[node],low[i]);
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int>adj[n];
        for(auto i:connections){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
         int time[n];int low[n];
        vector<int>visited(n,0);
         vector<vector<int>> bridges;
        dfs(0,-1,visited,adj,time,low,bridges);
        return bridges;
    }
};