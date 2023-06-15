class Solution {
public:
    int strStr(string haystack, string needle) {
        // 1 line solution
     // return haystack.find(needle);
        
        // Approach 2 substring
         int n=haystack.length();
        int m=needle.length();
        for(int i=0;i<n;i++){
            if(haystack.substr(i,m)==needle)
                return i;
        }
        return -1;
        
        
        
    }
};