//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
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
    int MaxConnection(vector<vector<int>>& grid) {
        int n=grid.size();
        DisjointSet ds(n*n);
        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                  int dr[] = { -1, 0, 1, 0};
                int dc[] = {0, -1, 0, 1};
               if(grid[row][col]==0) continue;
               for(int index=0;index<4;index++){
                   int newr=dr[index]+row;
                   int newc=dc[index]+col;
                   if(newr>=0 && newr<n && newc>=0 && newc<n && grid[newr][newc]==1){
                       int node=row*n+col;
                       int adjnode=newr*n+newc;
                       ds.unionBySize(node,adjnode);
                   }
               }
            }
        }
        int mx=0;
        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                  int dr[] = { -1, 0, 1, 0};
                int dc[] = {0, -1, 0, 1};
                set<int>components;
               if(grid[row][col]==1) continue;
               for(int index=0;index<4;index++){
                   int newr=dr[index]+row;
                   int newc=dc[index]+col;
                   if(newr>=0 && newr<n && newc>=0 && newc<n && grid[newr][newc]==1 )
                    components.insert(ds.findUPar(newr*n+newc));
               }
               int totalsize=0;
               for(auto i:components){
                   totalsize+=ds.size[i];
               }
               mx=max(mx,totalsize+1);
            }
        }
        for(int cell=0;cell<n*n;cell++)
        mx=max(mx,ds.size[ds.findUPar(cell)]);
        return mx;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }

        Solution obj;
        cout<<obj.MaxConnection(grid)<<"\n";
    }
}

// } Driver Code Ends