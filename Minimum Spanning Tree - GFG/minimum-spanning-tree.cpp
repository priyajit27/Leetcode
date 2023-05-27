//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class DisjointSet{
     vector<int>parent,size;
     public:
     DisjointSet(int n){
         size.resize(n+1,1);
         parent.resize(n+1);
         for(int i=0;i<n;i++){
            parent[i] = i;
         }
     }

     int findUPar(int node){
        if(parent[node]==node)
        return node;
        return parent[node]=findUPar(parent[node]);
     }

     void unionBySize(int u,int v){
           int ulp_u=findUPar(u);
           int ulp_v=findUPar(v);
           if(ulp_u==ulp_v)return;
           if(size[ulp_u]<size[ulp_v]){
               parent[ulp_u]=ulp_v;
               size[ulp_v]+=size[ulp_u];
           }
           else{
             parent[ulp_v]=ulp_u;
               size[ulp_u]+=size[ulp_v];
           }

     }
};
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
	
// 	Using Prims Algo
    // int spanningTree(int V, vector<vector<int>> adj[])
    // {
    //     priority_queue<pair<int, int>,
		  //             vector<pair<int, int> >, greater<pair<int, int>>> pq;
		  //             vector<int>visited(V,0);
		  //            // wt node
		  //             pq.push({0,0});
		  //             int sum=0;
		  //             while(!pq.empty()){
		  //                // logE
		  //                 int dis=pq.top().first;
		  //                 int node=pq.top().second;
		  //                 pq.pop();
		                   
		  //                 if(visited[node]==1)
		  //                 continue;
		  //                 visited[node]=1;
		  //                 sum+=dis;
		                   
		  //                // E*logE
		  //                 for(auto i:adj[node]){
		  //                     int adjnode=i[0];
		  //                     int d=i[1];
		  //                     if(!visited[adjnode])
		  //                     pq.push({d,adjnode});
		  //                 }
		  //             }
		  //             return sum;
    // }
    
    // Using khuskral algo disjoint set
           int spanningTree(int V, vector<vector<int>> adj[]){
              vector<pair<int,pair<int,int>> >edges;
              for(int i=0;i<V;i++){
                  for(auto it:adj[i]){
                      int adjnode=it[0];
                      int wt=it[1];
                      int node=i;
                      edges.push_back({wt,{node,adjnode}});
                  }
              }
                DisjointSet ds(V);
               sort(edges.begin(),edges.end());
               int mstsum=0;
               for(auto i:edges){
                   int wt=i.first;
                   int node=i.second.first;
                   int adjnode=i.second.second;
                   if(ds.findUPar(node)!=ds.findUPar(adjnode)){
                       mstsum+=wt;
                       ds.unionBySize(node,adjnode);
                   }
               }
            return mstsum;
           }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends