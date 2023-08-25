class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans="";
        stack<char>st;
        for(auto n:num){
            while(!st.empty() && st.top()>n  && k>0){
                st.pop();
                k--;
            }
            if(st.empty() && n=='0')
                continue;
         st.push(n);
        }
        
        while(!st.empty() && k!=0){
            st.pop();
            k--;
        }
        if(st.size()==0)return "0";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};