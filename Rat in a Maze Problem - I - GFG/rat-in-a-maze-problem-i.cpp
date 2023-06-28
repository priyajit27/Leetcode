//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void solve(int row,int col,int dr[] ,int dl[],vector<vector<int>> & m,int n,  vector<string>& ans,
      vector<vector<int>>& visited,string move){
        
        if(row==n-1 && col==n-1){
            ans.push_back(move);
            return ;
        }
        
        string dir="DLRU";
        
        for(int i=0;i<4;i++){
            int drow=dr[i]+row;
            int dcol=dl[i]+col;
            
            if(drow>=0 && dcol>=0 && drow<n && dcol<n && visited[drow][dcol]!=1 && m[drow][dcol]==1){
                visited[row][col]=1;
                  solve(drow,dcol,dr,dl,m,n,ans,visited,move+dir[i]);
                  visited[row][col]=0;
            }
        }
        
    }
   
    vector<string> findPath(vector<vector<int>> &m, int n) {
              vector<string> ans;
              
              vector<vector<int>>visited(n,vector<int>(n,0));
              
              int dr[]={1,0,0,-1};
              int dl[]={0,-1,1,0};
              if(m[0][0]==1)
              solve(0,0,dr,dl,m,n,ans,visited,"");
              
    
    //   return ans;
              
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
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends