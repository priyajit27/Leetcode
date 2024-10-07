class Solution {
public:
    string longestCommonPrefix(vector<string>& s) {
      //  int n=s.size();
      // int ans=s[0].length();
      //   for(int i=1;i<n;i++){
      //      int  j=0;
      //       while(j<s[0].length() && s[0][j]==s[i][j])j++;
      //       ans=min(ans,j);
      //   }
      //   return s[0].substr(0,ans);
        
         int n=s.size();
      int ans=s[0].length();
        int minm=INT_MAX;
       for(int i=1;i<n;i++){
           string str=s[i];
           int count=0;
           for(int j=0;j<str.length();j++){
               if(str[j]==s[0][j])
                   count++;
               else break;
           }
           minm=min(minm,count);
       }  
        return s[0].substr(0,minm);
    }
};