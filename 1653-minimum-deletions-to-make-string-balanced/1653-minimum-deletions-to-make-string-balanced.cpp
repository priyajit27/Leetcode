class Solution {
public:
    int minimumDeletions(string s) {
        stack<char>st;
        int ans=0;
        for(auto i:s){
           if(!st.empty() && st.top()=='b'){
               if(i=='a'){
                      st.pop();ans++;
               }
                   // st.pop();
               else
                  st.push(i);  
           }
            else
             st.push(i);
        }
        return ans;
    }
};