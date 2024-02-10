class Solution {
public:
    int rec(string& s,int i,int j){
        int count=0;
        while(i>=0 && j<s.length() && s[i]==s[j]){
            count++;
            i--;
            j++;
        }
        return count;
    }
    int countSubstrings(string s) {
        int ans=0;
        for(int i=0;i<s.length();i++){
            int odd=rec(s,i,i);
            ans+=odd;
             int even=rec(s,i,i+1);
            ans+=even;
        }
        return ans;
    }
};