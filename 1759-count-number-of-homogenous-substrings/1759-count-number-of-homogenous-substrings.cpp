class Solution {
public:
    int countHomogenous(string s) {
        int ans=1;
        int count=1;
        int mod=1e9+7;
        for(int i=1;i<s.length();i++){
            if(s[i-1]==s[i]){
                count++;
                // cout<<count;
                ans+=count;
                // cout<<ans;
                ans=ans%mod;
            }
            else{
               count=1; 
                ans+=1;
            }
        }
        return ans;
    }
};