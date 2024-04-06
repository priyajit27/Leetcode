class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n=s.length();
        int o=0;
        int close=0;
        string ans;
        for(int i=0;i<n;i++){
            char c=s[i]  ;
            if(c!=')' && c!='('){
                ans+=c;
            }
            else if(c=='('){
                ans+=c;
                o++;
            }
             else if(o>0){
                ans+=c;
                 o--;
            }
        }
        
        if(o>0){
            s=ans;
            n=s.length();
              ans="";
        for(int i=n-1;i>=0;i--){
            char c=s[i]  ;
            if(c!=')' && c!='('){
                ans+=c;
            }
            else if(c==')'){
                ans+=c;close++;
            }
             else if(close>0){
                ans+=c;
                 close--;
            }
        }
        
        }
        else
            return ans;
        
        
        
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};