class Solution {
public:
    void rec(int n,vector<vector<int>>& ans, vector<int>& sub,int k,int num){
           if(k==0){
                ans.push_back(sub);
               return;
           }
        if(num==n+1)return;
        
          // take
        sub.push_back(num);
          rec(n,ans,sub,k-1,num+1);
         sub.pop_back();
         
        
        
     // not take
          rec(n,ans,sub,k,num+1);
        
        
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int>sub;
        rec(n,ans,sub,k,1);
        return ans;
    }
};