class Solution {
public:
    int strStr(string haystack, string needle) {
        // 1 line solution
     // return haystack.find(needle);
        
        // Approach 2 substring
        //  int n=haystack.length();
        // int m=needle.length();
        // for(int i=0;i<n;i++){
        //     if(haystack.substr(i,m)==needle)
        //         return i;
        // }
        // return -1;
        
        
        
        // Approach 3  two pointers
        int n=haystack.length();
        int m=needle.length();
        
          if(haystack==needle)
            return 0;
        if(m>n)
            return -1;
        int i=0;
        int j=0;int start=0;
        while(i<n && j<m){
             if(haystack[i]==needle[j]){
                 if(j+1==m)
                     return start;
                 i++;j++;
             }
            else{
                j=0;
                start++;
                i=start;
            }
        }
        return -1;
        
    }
};