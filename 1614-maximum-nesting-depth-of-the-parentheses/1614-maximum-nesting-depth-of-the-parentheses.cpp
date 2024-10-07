class Solution {
public:
    int maxDepth(string s) {
        int ans=0;
        int maxm=0;
        for(auto i:s){
            if(i=='('){
                ans++;
                // maxm=max(ans,maxm);
            }
            else if(i==')')
                ans--;
              maxm=max(ans,maxm);
        }
        return maxm;
    }
};