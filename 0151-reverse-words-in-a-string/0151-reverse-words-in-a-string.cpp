class Solution {
public:
    string reverseWords(string s) {
        stack<string>st;
        string ans="";
        string word="";
        for(int i=0;i<s.length();i++){
            if(s[i]!=' ')
              word+=s[i];
            else if(word!=""){
               st.push(word);
                word="";
            }    
        }
        if(word!="")
        st.push(word);
         while(!st.empty()){
                ans+=st.top();
               st.pop();
             if(!st.empty())
                 ans+=' ';
                }
        return ans;
    }
};