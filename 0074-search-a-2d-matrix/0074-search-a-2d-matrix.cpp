class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         N*M (T.C)
//         brute force
        // int m=matrix.size();
        // int n=matrix[0].size();
        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         if(matrix[i][j]==target)
        //             return true;
        //     }
        // }
        // return false;
        
        
//         binary search
        int row=matrix.size();
        int col=matrix[0].size();
        int start=0;int end=row*col-1;  
            while(start<=end){
                int mid=start+(end-start)/2;
                int num=matrix[mid/col][mid%col];
                if(num==target)
                    return true;
                else if(num<target)
                    start=mid+1;
                else
                    end=mid-1;
            }
        return false;
    }
};