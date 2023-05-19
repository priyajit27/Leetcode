class Solution {
public:
     bool check(int source,vector<int>& visited,vector<vector<int>>& graph){
  visited[source]=1;
  queue<int>q;
  q.push(source);
  while(!q.empty()){
      int node=q.front();
      q.pop();
      for(auto i:graph[node]){
          if(visited[i]==-1){
              q.push(i);
              visited[i]=!visited[node];
          }
          else if(visited[node]==visited[i])
          return false;
      }
  }
 return true;  
}
    bool isBipartite(vector<vector<int>>& graph) {
         vector<int>visited(graph.size(),-1);
      for(int i=0;i<graph.size();i++){
          if(visited[i]==-1){
              if(check(i,visited,graph)==false)
              return false;
          }
      }
      return true;
	}
};