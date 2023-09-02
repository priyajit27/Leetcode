class Solution {
public:
    int rec(int i,string& s, unordered_set<string>& mp,  vector<int>& dp){
        // if(i>=s.size())return 0;
        //      if (dp[i] != -1) return dp[i]; 
        // string s1="";
        // int minextra=s.size();
        // for(int j=i;j<s.size();j++){
        //     s1.push_back(s[j]);
        //     int currextra=(mp.find(s1)!=mp.end())?0:s1.size();
        //     int nextextra=rec(j+1,s,mp,dp);
        //         int totalextra=currextra+nextextra;
        //     minextra=min(totalextra,minextra);
        // }
        // return dp[i]=minextra;
        
          if(i>=s.size())return 0;
        if(dp[i] != -1)return dp[i];
        int a = 1+ rec(i+1,s,mp,dp);
        string s1 = "";
        for(int j = i; j < s.size(); j++){
            s1 += s[j];
            if(mp.count(s1)){
                a = min(a,rec(j+1,s,mp,dp));
            }
        }
        return dp[i] = a;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
       int n = s.length();
        vector<int> dp(n,-1);
        unordered_set<string> st;
        for(auto &i: dictionary){
            st.insert(i);
        }
        return rec(0,s,st,dp);
    }
};