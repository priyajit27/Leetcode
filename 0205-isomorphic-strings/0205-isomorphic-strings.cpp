class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char>mp1;
         unordered_map<char,char>mp2;
        
        for(int i=0;i<s.length();i++){
             // if both of them don't contain that characer insert it
            if(!mp1.count(s[i]) && !mp2.count(t[i])){
                mp1[s[i]]=t[i];
                mp2[t[i]]=s[i];
            }
            else if( mp1[s[i]]!=t[i] || mp2[t[i]]!=s[i])
                return false;
                
        }
        return true;
    }
};