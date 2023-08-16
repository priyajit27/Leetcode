class Solution {
public:
    string simplifyPath(string path) {
        string ans="";
        int n=path.size();
        stack<string>st;
        for(int i=0;i<n;i++){
            if(path[i]=='/')continue;
            string str;
            while(i<n && path[i]!='/' ){
                str+=path[i];
                i++;
            }
            
            if(str==".")
                continue;
            else if(str==".."){
                if(!st.empty()){
                    st.pop();
                }
            }
            else
                st.push(str);
        }
        while(!st.empty()){
            ans='/'+st.top()+ans;
            st.pop();
        }
        if(ans.size()==0)
            return "/";
        return ans;
    }
};