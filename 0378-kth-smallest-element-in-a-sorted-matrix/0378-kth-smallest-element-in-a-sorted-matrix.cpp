class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector<int>ans;
        for(int i=0;i<matrix[0].size();i++){
            for(int j=0;j<matrix.size();j++){
                ans.push_back(matrix[i][j]);
            }
        }
        sort(ans.begin(),ans.end());
        int ans1=-1;
       for(int i=0;i<k;i++) 
           ans1=ans[i];
        return ans1;
    }
};