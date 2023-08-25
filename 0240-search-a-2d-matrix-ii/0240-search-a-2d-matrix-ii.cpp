class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
       //         N*M (T.C)
        // brute force
        // int m=matrix.size();
        // int n=matrix[0].size();
        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         if(matrix[i][j]==target)
        //             return true;
        //     }
        // }
        // return false;
        
         int i=0;
        int j=matrix[0].size()-1;
        
        while(i<matrix.size() && j>=0){
            if(matrix[i][j]==target)return true;
            else if(target>matrix[i][j])i++;
                else j--;
        }
         return false;
    }
};