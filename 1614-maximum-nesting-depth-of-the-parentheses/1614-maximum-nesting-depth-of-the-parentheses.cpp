class Solution {
public:
    int maxDepth(string s) {
        
        // TC O(N) SC  O(N)
        stack<char>st;
        int count=0;
        int maxm=0;
        for(int i=0;i<s.length();i++){
            
            // if(count>maxm)
                maxm=max(maxm,count);
            
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
        
        
//           // TC O(N) SC  O(1)
//         int count=0;
        
//         for(int i=0;i<s.length();i++){
//             if(s[i]==')')count++;
//             else if(s[i]=='(' && count>0)count--;
//         }
        
//         return count;
    }
};