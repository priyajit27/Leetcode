class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<int>>costt(26,vector<int>(26,INT_MAX));
        int n=cost.size();
         for(int i=0;i<26;i++){
            costt[i][i]=0;
        }
        for(int i=0;i<n;i++){
            costt[original[i]-'a'][changed[i]-'a']=min(costt[original[i]-'a'][changed[i]-'a'],cost[i]);
        }
         for(int k=0;k<26;k++){
        for(int i=0;i<26;i++){
              for(int j=0;j<26;j++){
              // for(int k=0;k<26;k++){
                  if(costt[i][k]!=INT_MAX && costt[k][j]!=INT_MAX)
           costt[i][j] =min(costt[i][j],costt[i][k]+costt[k][j]);
        }}}
        long long ans=0;
        for(int i=0;i<source.size();i++){
            if(costt[source[i]-'a'][target[i]-'a']==INT_MAX)return -1;
            ans+=costt[source[i]-'a'][target[i]-'a'];
        }
        return ans;
    }
};