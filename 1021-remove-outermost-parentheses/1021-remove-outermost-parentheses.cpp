class Solution {
public:
    string removeOuterParentheses(string s) {
//         O(N)  O(N)
        stack<char>st;
        string res="";
        for(int i=0;i<s.length();i++){
            if(st.empty() && s[i]=='(')
                st.push(s[i]);
            else if(s[i]=='('){
                res+=s[i];
                st.push(s[i]);
            }
            else{
                 st.pop();
                if(st.size())
                res+=s[i];
            }
        }
        return res;
    }
};