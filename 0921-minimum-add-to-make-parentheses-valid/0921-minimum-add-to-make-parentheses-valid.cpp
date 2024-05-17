class Solution {
public:
    int minAddToMakeValid(string s) {
        int ans=0;
        int ans1=0;
        for(auto i:s){
            if(i=='(')
                ans++;
            else{
                if(ans>0)ans--;
                else ans1++;
            }
                // ans--;
        }
        return ans+ans1;
    }
};