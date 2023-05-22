//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int MinimumEffort(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
           // in the form {difference,{cell coordinates pair}}.
         priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,greater<pair<int, pair<int, int>>>>
            pq;
        
        vector<vector<int>>dist(n,vector<int>(m,1e8));
        dist[0][0]=0;
        
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        
        pq.push({0,{0,0}});
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int diff=it.first;
            int r=it.second.first;
            int c=it.second.second;
            
            if(r==n-1 && c==m-1)
            return diff;
            
            for(int i=0;i<4;i++){
                int newr=r+dr[i];
                int newc=c+dc[i];
                if(newr>=0 && newr<n && newc>=0 && newc<m){
                   int neweffort=max(abs(heights[r][c]-heights[newr][newc]),diff);
                   if(neweffort<dist[newr][newc]){
                       dist[newr][newc]=neweffort;
                       pq.push({neweffort,{newr,newc}});
                   }
                }
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m; cin>>n>>m;
        vector<vector<int>> heights;
       
        for(int i=0; i<n; ++i){
            vector<int> temp;
            for(int j=0; j<m; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            heights.push_back(temp);
        }
       
        Solution obj;
        cout<<obj.MinimumEffort(heights)<<"\n";
    }
    return 0;
}
// } Driver Code Ends