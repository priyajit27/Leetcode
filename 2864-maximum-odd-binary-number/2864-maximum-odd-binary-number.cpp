class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n=s.length();
        int one=0;
        int z=0;
        for(int i=0;i<n;i++){
            if(s[i]=='0')z++;
            else one++;
        }
        sort(s.begin(),s.end());
        for(int i=0;i<one-1;i++){
            s[i]='1';
        }
          for(int i=one-1;i<n-1;i++){
            s[i]='0';
        }
        return s;
    }
};