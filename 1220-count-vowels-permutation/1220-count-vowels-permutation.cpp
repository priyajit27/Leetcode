#define mod 1000000007
class Solution {
public:
    long long rec(char c,int n,int ind,vector<vector<int>>& dp,map<char,int>& mp){
        if(ind==n)
            return 1;
        
        long long count=0;
        if(dp[mp[c]][ind]!=-1)return dp[mp[c]][ind]%mod;
        
        if(c=='a'){
            count+= rec('e',n,ind+1,dp,mp);
        }
         else if(c=='e'){
            count+= rec('a',n,ind+1,dp,mp);
             count+= rec('i',n,ind+1,dp,mp);
        }
         else if(c=='i'){
             count+= rec('a',n,ind+1,dp,mp);
             count+= rec('e',n,ind+1,dp,mp); 
             count+= rec('o',n,ind+1,dp,mp);
             count+= rec('u',n,ind+1,dp,mp);
        }
         else if(c=='o'){
             count+= rec('u',n,ind+1,dp,mp);
             count+= rec('i',n,ind+1,dp,mp);
        }
        else{
            count+= rec('a',n,ind+1,dp,mp);
        }
        
        return dp[mp[c]][ind]= count%mod;
    }
    int countVowelPermutation(int n) {
       map<char,int>mp;
        mp['a']=0;
        mp['e']=1; mp['i']=2; mp['o']=3; mp['u']=4;
        
        vector<vector<int>>dp(5,vector<int>(n+1,-1));
        long long ans=(rec('a',n,1,dp,mp)+rec('e',n,1,dp,mp)+rec('i',n,1,dp,mp)+rec('o',n,1,dp,mp)+rec('u',n,1,dp,mp))%mod;
            
            return ans%mod;
    }
};