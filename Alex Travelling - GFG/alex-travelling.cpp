//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int minimumCost(vector<vector<int>>& flights, int n, int k) {
           vector<pair<int,int>>adj[n+1];
        for(auto i:flights)
            adj[i[0]].push_back({i[1],i[2]});
        
         priority_queue< pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>> > pq;
        pq.push({0,k});
        vector<int>dist(n+1,1e8);
        dist[0]=0;
        dist[k]=0;
        while(!pq.empty()){
           auto it=pq.top() ;
            pq.pop();
            int dis=it.first;
            int node=it.second;
            
            for(auto i:adj[node]){
                int adjnode=i.first;
                int d=i.second;
                if(d+dis<dist[adjnode]){
                    dist[adjnode]=d+dis;
                    pq.push({d+dis,adjnode});
                }
            }
        }
        int ans=-1;
        for(int i=1;i<=n;i++){
           if(dist[i]==1e8) return -1;
            ans=max(ans,dist[i]) ;
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int size;
        cin >> size;
        vector<vector<int>> flights(size,vector<int>(3));
        for (int i = 0; i < size; i++) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            flights[i]=temp;
        }

        Solution ob;
        cout << ob.minimumCost(flights, n, k) << "\n";
    }
}

// } Driver Code Ends