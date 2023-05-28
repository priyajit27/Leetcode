class DisjointSet{
     // vector<int>parent,size;
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
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        int maxrow=0;int maxcol=0;
        for(auto i:stones){
            maxrow=max(maxrow,i[0]);
            maxcol=max(maxcol,i[1]);
        }
        unordered_map<int,int>mp;
         DisjointSet ds(maxrow+maxcol+2);
        int count=0;
        for(auto i:stones){
            int rownode=i[0];
             int colnode=i[1]+maxrow+1;
            ds.unionBySize(rownode,colnode);
            mp[rownode]=1;
            mp[colnode]=1;
        }  
        for(auto it:mp){
            if(ds. findUPar(it.first)==it.first)
                count++;
        }
        return n-count;
    }
};