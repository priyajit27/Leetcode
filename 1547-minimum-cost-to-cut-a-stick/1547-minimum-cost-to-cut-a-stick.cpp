class Solution {
public:
    int  rec(int i,int j, vector<int>& cuts, vector<vector<int>>& dp){
        if(i>j)
            return 0;
        long long mini=INT_MAX;
        if(dp[i][j]!=-1)
            return dp[i][j];
        for(int k=i;k<=j;k++){
            long long ans=cuts[j+1]-cuts[i-1]+rec(i,k-1,cuts,dp)+rec(k+1,j,cuts,dp);
            mini=min(ans,mini);
        }
        return dp[i][j]=mini;
    }
    int minCost(int n, vector<int>& cuts) {
        // cuts.push_back(n);
        // cuts.insert(cuts.begin(),0);
        // sort(cuts.begin(),cuts.end());
        //  vector<vector<int>> dp(n,vector<int>(n,-1));
        // return rec(1,cuts.size()-2,cuts,dp);
        
        
        cuts.insert(cuts.begin(),0);
		cuts.insert(cuts.end(),n);
		sort(cuts.begin(),cuts.end());
		int m=cuts.size();
		vector<vector<int>> dp(m,vector<int>(m,0));
		for(int i=m-1;i>=1;i--){
			for(int j=i;j<=m-2;j++){
				int mini=1e9;
				for(int ind=i;ind<=j;ind++){
					int cost= cuts[j+1]-cuts[i-1]+dp[i][ind-1]+dp[ind+1][j];
					mini=min(mini,cost);
				}
				dp[i][j]=mini;
			}
		}
		return dp[1][cuts.size()-2];
    }
};