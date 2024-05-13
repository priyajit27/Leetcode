class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& m) {
        int n=m.size();
        vector<vector<int>>ans(n-2,vector<int>(n-2));
        for(int i=1;i<n-1;i++){
          for(int j=1;j<n-1;j++){
            ans[i-1][j-1]=max({
                    m[i-1][j-1], m[i-1][j], m[i-1][j+1],
                    m[i][j-1],   m[i][j],   m[i][j+1],
                    m[i+1][j-1], m[i+1][j], m[i+1][j+1]
                });
        }   
        }
        
        return ans;
    }
};