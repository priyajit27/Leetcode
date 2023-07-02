class Solution {
public:
    string removeOuterParentheses(string s) {
//         O(N)  O(N)
        // stack<char>st;
        // string res="";
        // for(int i=0;i<s.length();i++){
        //     if(st.empty() && s[i]=='(')
        //         st.push(s[i]);
        //     else if(s[i]=='('){
        //         res+=s[i];
        //         st.push(s[i]);
        //     }
        //     else{
        //          st.pop();
        //         if(st.size())
        //         res+=s[i];
        //     }
        // }
        // return res;
        
        // without space complexity
        
        string res="";
        int balance=0;
        
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                if(balance>0)
                   res+=s[i] ;
                    balance++;
            }
            else{
               balance--;
                  if(balance>0)
                   res+=s[i] ;
            }
        }
        return res;
    }
};