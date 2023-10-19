class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char>st;
        string s1="";
        string s2="";
        for(int i=0;i<s.length();i++){
            // st.push(s[i]);
            if(s[i]=='#' && !st.empty())
                st.pop();
            else if(s[i]=='#'  && st.empty())
                continue;
             else 
               st.push(s[i]); 
        }
        
        while(!st.empty()){
            s1+=st.top();
            st.pop();
        }
        cout<<s1<<endl;
        
        for(int i=0;i<t.length();i++){
            // st.push(t[i]);
            if(t[i]=='#'  && !st.empty())
                st.pop();
              else if(t[i]=='#'  && st.empty())
                continue;
            else
               st.push(t[i]);  
        }
        
         while(!st.empty()){
            s2+=st.top();
            st.pop();
        }
        cout<<s2;
        
        if(s1==s2)return true;
        return false;
    }
};