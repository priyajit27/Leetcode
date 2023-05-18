class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
//          process
        // 1 2 3      1 4 7      7 4 1
        // 4 5 6 ->   2 5 8 ->   8 5 2
        // 7 8 9      3 6 9      9 6 3
        int n=matrix.size();
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
               swap(matrix[i][j],matrix[j][i]);
            }
        }
        for(int i=0;i<n;i++)
        reverse(matrix[i].begin(),matrix[i].end());
    }
};