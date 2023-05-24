//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  int rec(int index,int last,vector<vector<int>>& points,vector<vector<int>>& dp){
      if(dp[index][last]!=-1)
      return dp[index][last];
      if(index==0){
          int maxi=0;
          for(int i=0;i<3;i++){
              if(i!=last)
                  maxi=max(maxi,points[0][i]);
          }
          return dp[index][last]=maxi;
      }
      int maxi=0;
      int point=0;
      for(int i=0;i<3;i++){
         if(i!=last) {
            point=points[index][i]+rec(index-1,i,points,dp);
         }
         maxi=max(maxi,point);
      }
      return maxi;
  }
   int tabulation(int n,vector<vector<int>>& points){
     
     vector<vector<int>>dp(n,vector<int>(4,0));
     dp[0][0]=max(points[0][1],points[0][2]);
     dp[0][1]=max(points[0][0],points[0][2]);
     dp[0][2]=max(points[0][1],points[0][0]);
     dp[0][3]=max(points[0][1],max(points[0][2],points[0][0]));
     for(int day=1;day<n;day++)
     for(int last=0;last<4;last++){
         dp[day][last]=0;
          for(int task=0;task<3;task++){
         if(task!=last) {
           int point=points[day][task]+dp[day-1][task];
           dp[day][last]=max( dp[day][last],point);
         }
      }
     }
      return dp[n-1][3];
  }
   int space(int n,vector<vector<int>>& points){
     
     vector<int>prev(4,0);
    //  vector<int>curr(4,0);
     prev[0]=max(points[0][1],points[0][2]);
     prev[1]=max(points[0][0],points[0][2]);
     prev[2]=max(points[0][1],points[0][0]);
     prev[3]=max(points[0][1],max(points[0][2],points[0][0]));
     for(int day=1;day<n;day++){
         vector<int>curr(4,0);
     for(int last=0;last<4;last++){
         curr[last]=0;
          for(int task=0;task<3;task++){
         if(task!=last) {
           int point=points[day][task]+prev[task];
           curr[last]=max(curr[last],point);
         }
      }}
      prev=curr;
     }
      return prev[3];
  }
    int maximumPoints(vector<vector<int>>& points, int n) {
        // vector<vector<int>>dp(n,vector<int>(4,-1));
        // return rec(n-1,3,points,dp);
        
        // return tabulation(n,points);
        
        return space(n,points);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> points;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            points.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(points, n) << endl;
    }
    return 0;
}
// } Driver Code Ends