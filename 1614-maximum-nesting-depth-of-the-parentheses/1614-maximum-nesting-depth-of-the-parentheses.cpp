class Solution {
public:
    int maxDepth(string s) {
        stack<char>st;
        int count=0;
        int maxm=0;
        for(int i=0;i<s.length();i++){
            
            if(count>maxm)
                maxm=count;
            
           if(s[i]=='('){
               count++;
               st.push(s[i]);
           }
            else if(s[i]==')'){
                count--;
                st.pop();
            }
        }
        
        return maxm;
        
//         int count=0;
        
//         for(int i=0;i<s.length();i++){
//             if(s[i]==')')count++;
//             else if(s[i]=='(' && count>0)count--;
//         }
        
        // return count;
    }
};