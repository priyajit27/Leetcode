class Solution {
public:
    int findmaxindex(vector<vector<int>>& mat,int n,int m,int mid){
        
        int maxmvalue=-1;
        int maxmindex=-1;
        for(int i=0;i<n;i++){
            if(mat[i][mid]>maxmvalue){
                maxmindex=i;
                maxmvalue=mat[i][mid];
            }
        }
        return maxmindex;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int low=0;
        int high=m-1;
        int mid;
        while(low<=high){
            mid=(low+high)/2;
            int rowmaxindex=findmaxindex(mat,n,m,mid);
            int left=mid>0?mat[rowmaxindex][mid-1] : -1;
            int right=mid<m-1?mat[rowmaxindex][mid+1] : -1;
            if(mat[rowmaxindex][mid]>left && mat[rowmaxindex][mid]>right){
                return {rowmaxindex,mid};
            }
            else if(mat[rowmaxindex][mid]<left)
                high =mid -1;
            else
                low=mid+1;
        }
        return {-1,-1};
    }
};