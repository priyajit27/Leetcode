class Solution {
public:
     bool rec(string s,int i,int j) {
        while(i<=j){
            if(s[i]!=s[j])
                return false;
            i++;j--;
        }
        return true;
     }
    bool validPalindrome(string s) {
        int i=0;
        int j=s.length()-1;
        int count=1;
        while(i<=j){
            if(s[i]!=s[j]){
                return rec(s,i,j-1) || rec(s,i+1,j);
            }  
            else{
                i++;j--;
            }
        }
        return true;
    }
};