//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class DisjointSet{
    //  vector<int>parent,size;
     public:
     vector<int>parent,size;
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
class Solution {
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        // Using disjoint set
         DisjointSet ds(V) ;
         for(int i=0;i<V;i++){
             for(int j=0;j<V;j++){
                 if(adj[i][j]==1){
                     ds.unionBySize(i,j);
                 }
             }
         }
         int count=0;
         for(int i=0;i<V;i++){
             if(ds.findUPar(i)==i)
             count++;
         }
        return count;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends