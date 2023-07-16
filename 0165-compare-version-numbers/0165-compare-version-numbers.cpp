class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i=0,j=0;
        int n=version1.size();
        int m=version2.size();
        
        while(i<n || j<m){
           long long a=0;
            long long b=0;
            
            while(i<n && version1[i]!='.'){
                a=10*a+version1[i]-'0';
                i++;
            }
            
             while(j<m && version2[j]!='.'){
                 b=10*b+version2[j]-'0';
                j++;
            }
            if(a>b)return 1;
            if(b>a)return -1;
            
            i++;j++;
        }
        return 0;
    }
};