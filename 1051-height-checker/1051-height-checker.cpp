class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int n=heights.size();
        vector<int>a(n);
        for(int i=0;i<n;i++)a[i]=heights[i];
        sort(a.begin(),a.end());
        int ans=0;
        for(int i=0;i<n;i++){
            if(a[i]!=heights[i])ans++;
        }
        return ans;
    }
};