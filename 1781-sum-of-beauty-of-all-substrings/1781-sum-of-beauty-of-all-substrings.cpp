class Solution {
public:
    int beautySum(string s) {
        int n=s.length();
        int ans=0;
        for(int i=0;i<n;i++){
             int freq[26]={0};
            for(int j=i;j<n;j++){
                 freq[s[j]-'a']++;
                  int maxm=0;int minm=n;
                for(auto i:freq){
                    if(i>0){
                    maxm=max(maxm,i);
                    minm=min(minm,i);
                    }
                }
                ans+=maxm-minm;
            }
        }
        return ans;
    }
};