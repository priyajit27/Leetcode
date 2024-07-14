class Solution {
public:
  bool check(string s){
      for(int i=0;i<s.length()-1;i++){
          if(s[i]=='0' && s[i+1]=='0')
              return false;
      }
      return true;
  }
    void rec(int n,string s,  vector<string>& ans){
        if(s.length()==n){
           if(check(s)) ans.push_back(s);
            return;
        }
        rec(n,s+'0',ans); rec(n,s+'1',ans);
    }
    vector<string> validStrings(int n) {
        vector<string>ans;
        string s="";
        rec(n,s,ans);   
    return ans;
    }
};