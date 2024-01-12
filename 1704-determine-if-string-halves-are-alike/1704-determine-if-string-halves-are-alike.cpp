class Solution {
public:
    bool vow(char s){
         char c=tolower(s);
        return (c=='a'||c=='e'||c=='i'||c=='o'||c=='u');
    }
    bool halvesAreAlike(string s) {
        int n=s.length();
        int x=0;
       for(int i=0;i<n/2;i++){
          if(vow(s[i]))x++;
          if(vow(s[n-i-1]))x--;
       }
        if(x==0)return true;
        return false;
    }
};