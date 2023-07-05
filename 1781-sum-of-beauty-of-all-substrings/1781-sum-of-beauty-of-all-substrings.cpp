class Solution {
public:
    int beautySum(string s) {
        
        // O(N^3)  Sc 0(N)
        // int n=s.length();
        // int ans=0;
        // for(int i=0;i<n;i++){
        //     for(int j=i;j<n;j++){
        //         int freq[26]={0};
        //         for(int k=i;k<=j;k++){
        //             freq[s[k]-'a']++;
        //         }
        //         int maxm=0;int minm=n+1;
        //         for(auto i:freq){
        //             maxm=max(maxm,i);
        //             minm=min(minm,i);
        //         }
        //         ans+=maxm-minm+1;
        //     }
        // }
        // return ans;
        
        
           int n=s.length();
        int ans=0;
        for(int i=0;i<n;i++){
             int freq[26]={0};
            for(int j=i;j<n;j++){
                 freq[s[j]-'a']++;
                  int maxm=0;int minm=n+1;
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