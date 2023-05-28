//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

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
class Solution {
  public:
    vector<vector<string>> mergeDetails(vector<vector<string>>& details) {
        int n=details.size();
        DisjointSet ds(n);
        //   sort(details.begin(), details.end());
        unordered_map<string,int>mp;
        for(int i=0;i<n;i++){
            for(int j=1;j<details[i].size();j++){
                string mail=details[i][j];
                if(mp.find(mail)==mp.end()){
                    mp[mail]=i;
                }
                else
                ds.unionBySize(mp[mail],i);
            }
        }
        
        vector<string>merge[n];
        for(auto it:mp){
            string mail=it.first;
            int node=ds.findUPar(it.second);
            merge[node].push_back(mail);
        }
        vector<vector<string>>ans;
        for(int i=0;i<n;i++){
            if(merge[i].size()==0)continue;
            sort(merge[i].begin(),merge[i].end());
            vector<string>temp;
            temp.push_back(details[i][0]);
            for(auto it:merge[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
         sort(ans.begin(), ans.end(),greater<vector<string>>());
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<string>> adj;

        for (int i = 0; i < n; i++) {
            vector<string> temp;
            string s;
            cin >> s;
            temp.push_back(s);
            int x;
            cin >> x;

            for (int j = 0; j < x; j++) {
                string s1;
                cin >> s1;
                temp.push_back(s1);
            }
            adj.push_back(temp);
        }

        Solution obj;
        vector<vector<string>> res = obj.mergeDetails(adj);
        sort(res.begin(),res.end(),[](const vector<string>& a, const vector<string>& b){
            return a[0]<=b[0];
        });
        cout << "[";
        for (int i = 0; i < res.size(); ++i) {
            cout << "[";
            for (int j = 0; j < res[i].size(); j++) {
                if (j != res[i].size() - 1)
                    cout << res[i][j] << ","
                         << " ";
                else
                    cout << res[i][j];
            }
            if (i != res.size() - 1)
                cout << "], ";
            else
                cout << "]";
        }
        cout << "]"
             << "\n";
    }
}

// } Driver Code Ends