class Solution {
public:

    string lastNonEmptyString(string s) {
        int n=s.length();
      vector<int>freq(26,0);
        for(auto i:s){
            freq[i-'a']++;
        }
        int maxm=0;
        for(auto i:freq){
            maxm=max(maxm,i);
        }
        string ans="";
        for(int i=n-1;i>=0;i-- ){
            if(freq[s[i]-'a']==maxm){
                 ans+=s[i];
                freq[s[i]-'a']=0;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};