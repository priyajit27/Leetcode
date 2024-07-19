class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
            vector<int>ans;
        for(int i=0;i<matrix.size();i++){
          for(int j=0;j<matrix[0].size();j++){
            int x=matrix[i][j];
              bool ok=true;
              for(int k=0;k<matrix.size();k++){
                  if(x<matrix[k][j]){
                      ok=false;
                      break;}
              }
               for(int l=0;l<matrix[0].size();l++){
                  if(x>matrix[i][l]){
                       ok=false;break;
                  }
              }
              if(ok)ans.push_back(x);
        }  
        }
        return ans;
    }
};