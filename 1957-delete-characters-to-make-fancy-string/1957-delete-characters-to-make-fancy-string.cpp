class Solution {
public:
    string makeFancyString(string s) {
        string ans="";
        ans+=s[0];
        int count=1;
        for(int i=1;i<s.length();i++ ){
            ans+=s[i];
            if(s[i-1]==s[i])
                count++;
            else
                count=1;
            if(count>=3)
                ans.pop_back();
            
        }
        return ans;
    }
};