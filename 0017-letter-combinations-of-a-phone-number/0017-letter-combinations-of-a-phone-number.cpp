class Solution {
public:
     vector<string>ans,phone;
    void rec(string& out,string& digits,int ind){
        
        if(ind==digits.size()){
            ans.push_back(out);
            return ;
        }
        
        
        int digit=digits[ind]-'0';
        string word=phone[digit];
        for(int i=0;i<word.length();i++){
              out.push_back(word[i]);
            rec(out,digits,ind+1);
            out.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0)
            return {};
        phone={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        string out="";
        rec(out,digits,0);
            return ans;
    }
};