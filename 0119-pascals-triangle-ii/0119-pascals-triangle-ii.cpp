class Solution {
public:
    vector<int> getRow(int rowIndex) {
          vector<vector<int>>ans;
        for(int i=0;i<=rowIndex;i++){
            vector<int>a(i+1,1);
            for(int j=1;j<i;j++){
                a[j]=ans[i-1][j-1]+ans[i-1][j];
            }
            ans.push_back(a);
        }
        return  ans[rowIndex];
    }
};