class Solution {
public:
     bool static compare(vector<int>a,vector<int>b){
        if(a[1]==b[1])
         return a[0] <b[0];
            return a[1]<b[1];
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(),compare);
        // for(auto i:pairs){
        //     cout<<i[0]<<" "<<i[1];
        // }
       
        // int start=pairs[1][0];
        int ans=1;
        int e=pairs[0][1];
        for(int i=1;i<pairs.size();i++){
          int start=pairs[i][0];
             int end=pairs[i][1];
            if(start>e){
                ans++;
                e=max(e,end);
            }
        }
        return ans;
    }
};