class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string str1="";
        string str2="";
        for(int i=0;i<s.length()/2;i++){
            str1+=s[i];
            str2=str1;
            if(s.length()%str2.length()==0){
                int n=s.length()/str2.length();
                while(n>1){
                  str2+=str1;
                    // cout<<str2;
                    n--;
                }
                if(str2==s)
                    return true;
            }
        }
        return false;
    }
};