class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int n=nums.size();
        map<int,int>mp;
        for(auto i:nums)
            mp[i]++;
        int maxm=0;
        for(auto i:mp){
            maxm=max(maxm,i.second);
        }
         vector<vector<int>>ans;
        
        for(int i=0;i<maxm;i++){
             vector<int>a={};
             for(auto& i:mp){
                 if(i.second>0){
                     a.push_back(i.first);
                     i.second--;       
             }}
            ans.push_back(a);
        }
       
        return ans;
    }
};