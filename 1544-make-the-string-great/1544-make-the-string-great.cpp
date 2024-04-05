class Solution {
public:
    string makeGood(string s) {
        int n=s.length();
        stack<char>st;
        if(s.size()<2)return s;
        
        for(int i=n-1;i>=0;i--){
            if(st.size() && abs(s[i]-st.top())=='a'-'A'){
                st.pop();
            }
            else
                st.push(s[i]);
        }
        string s1="";
        while(!st.empty()){
            s1+=st.top();
            st.pop();
        }
        return s1;
    }
};