class Solution {
public:
    bool findRotation(vector<vector<int>>& matrix, vector<vector<int>>& target) {
        // idea
        // Fisst a 90 degree rotate kormu then one by one jodi target ar songha match korsa then eta correct ans
        int n=matrix.size();
        if(matrix==target)
            return true;
        int rotate=3;
        while(rotate--){
              for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
               swap(matrix[i][j],matrix[j][i]);
            }
        }
        for(int i=0;i<n;i++)
        reverse(matrix[i].begin(),matrix[i].end());
        if(matrix==target)
            return true;
        }
        return false;
    }
};