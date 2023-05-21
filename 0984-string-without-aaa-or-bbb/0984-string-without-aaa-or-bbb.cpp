class Solution {
public:
    string strWithout3a3b(int a, int b) {
        string ans="";
        while(a && b){
            if(a>b){
                ans+="aab";
                a--;
            }
             else if(a<b){
                ans+="bba";
                b--;
            } 
            else{
                ans+="ab";
            }
            a--;b--;
        }
        while(b--)ans+="b";
        while(a--)ans+="a";
        return ans;
    }
};