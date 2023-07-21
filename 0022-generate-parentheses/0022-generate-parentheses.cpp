class Solution {
public:
    void rec(int left,int right,string s,vector<string> & ans){
        if(left==0 && right==0)
            ans.push_back(s);
        
        if(left>right || left<0 || right<0)
            return ;
        
        s.push_back('(');
            rec(left-1,right,s,ans);
        s.pop_back();
        
          s.push_back(')');
            rec(left,right-1,s,ans);
        s.pop_back();
        
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string s;
        rec(n,n,s,ans);
        return ans;
    }
};