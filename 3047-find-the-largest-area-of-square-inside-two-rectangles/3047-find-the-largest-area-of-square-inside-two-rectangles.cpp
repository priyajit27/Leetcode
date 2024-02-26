class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& b, vector<vector<int>>& t) {
        int n=b.size();
        long ans=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                   int p=max(b[i][0],b[j][0]);
                   int q=max(b[i][1],b[j][1]);
                   int r=min(t[i][0],t[j][0]);
                   int s=min(t[i][1],t[j][1]);
                if(p<r && q<s){
                    long  side=0;
                    if((r-p)>(s-q)){
                       // side=r-p; 
                        side=s-q;   
                    }
                    else
                    side=r-p; 
                ans=max(ans,side*side);   
                }
            }
        }
        return ans;
    }
};