class Solution {
public:
    bool isSubstringPresent(string s) {
        for(int i=1;i<s.length();i++){
            if(s[i]==s[i-1] || s[i-1]==s[i+1])
                return true;
        }
        return false;
    }
};