class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            vector<int>a(i+1,1);
            for(int j=1;j<i;j++){
                a[j]=ans[i-1][j-1]+ans[i-1][j];
            }
            ans.push_back(a);
        }
        return ans;
    }
};