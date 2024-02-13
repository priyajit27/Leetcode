class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for(auto i:words){
            string s=i;
            bool ok=true;
            for(int j=0;j<s.length();j++){
                if(s[j]==s[s.length()-j-1])continue;
                else{
                    ok=false;
                    break;
                }
            }
            if(ok==true){
                return s;
            }
        }
        return "";
    }
};