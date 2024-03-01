class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        // string str=s;
        int n=s.length();
        // str[n-1]='1';
        int one=0;
        int z=0;
        for(int i=0;i<n;i++){
            if(s[i]=='0')z++;
            else one++;
        }
        // one=one-1;
        //  int j=0;
        // while(one--){
        //     s[j]='1';j++;
        // }
        //  while(z--){
        //     s[j]='0';j++;
        // }
        // return str;
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