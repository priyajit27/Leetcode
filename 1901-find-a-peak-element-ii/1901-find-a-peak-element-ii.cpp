class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int i=0,j=0;
        // int left=-1,right=-1,up=-1,down=-1;
        while(1){
            int ele=matrix[i][j];
            int left=j-1>=0?matrix[i][j-1]:-1;
           int  up=i-1>=0?matrix[i-1][j]:-1;  
             int  right=j+1<m?matrix[i][j+1]:-1;
              // if(i+1<n)
            int  down=i+1<n?matrix[i+1][j]:-1;
            
            
            if(ele<left)ele=left;
            if(ele<right)ele=right;
            if(ele<up)ele=up;
            if(ele<down)ele=down;
            
            if(ele==left)j--;
             else if(ele==right)j++;
            else if(ele==up)i--;
            else if(ele==down)i++;
                else return{i,j};
        }
        

    }
};