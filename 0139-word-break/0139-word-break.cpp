class Solution {
public:
    bool rec(int i,string s,set<string>& sets,vector<string>& wordDict,vector<int>& dp){
        if(i==s.size())return true;
        if(dp[i]!=-1)return dp[i];
        
        for(int j=i;j<s.size();j++){
            string temp=s.substr(i,j-i+1);
            if(sets.find(temp)!=sets.end()){
                if(rec(j+1,s,sets,wordDict,dp))
                return dp[i] =true;
            }
        }
        return dp[i]=false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.length();
        set<string>sets(wordDict.begin(),wordDict.end());
        vector<int>dp(n+1,-1);
        return rec(0,s,sets,wordDict,dp);
    }
};