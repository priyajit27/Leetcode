class Solution {
public:
    void rec(int ind,string s,long sum,long prev,string& num, int target,vector<string>& ans){
        if(ind==num.size()){
            if(sum==target)
                ans.push_back(s);
        }
        
        for(int j=ind;j<num.size();j++){
            
            if(j>ind && num[ind]=='0')break;
            
            long nums=stol(num.substr(ind,j-ind+1));
            
            string temp=num.substr(ind,j-ind+1);
            
            if(ind==0)
                rec(j+1,temp,nums,nums,num,target,ans);
            else{
                rec(j+1,s+'+'+temp,sum+nums,nums,num,target,ans)  ;
                rec(j+1,s+'-'+temp,sum-nums,-nums,num,target,ans)  ;
                rec(j+1,s+'*'+temp,sum-prev+prev*nums,prev*nums,num,target,ans)  ;
                    
                }      
        }
            
    }
    vector<string> addOperators(string num, int target) {
         vector<string>ans;
        rec(0,"",0,0,num,target,ans);
        return ans;
    }
};