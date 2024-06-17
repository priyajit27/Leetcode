class Solution {
public:
     bool dfs(int node,vector<int>& visited,vector<vector<int>>& adj,vector<int>& pathvisited,vector<int> &check){
        visited[node]=1;
        pathvisited[node]=1;
             for(auto i:adj[node]){
            if(visited[i]==0){
               if(dfs(i,visited,adj,pathvisited,check)==true){
                   return true;
               }
            }
            else if(pathvisited[i]){
                 return true;
            }
        }
        pathvisited[node]=0;
         check[node]=1;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
//         like directed cyclic graph
        int v=adj.size();
        vector<int>safenodes;
          vector<int>check(v,0);
          vector<int>visited(v,0);
        vector<int>pathvisited(v,0);
       for(int i=0;i<v;i++){
           if(visited[i]==0){
               dfs(i,visited,adj,pathvisited,check);
           }
       }
        for(int i=0;i<v;i++){
            if(check[i]==1)
                safenodes.push_back(i);
        }
       return safenodes;
    }
};