class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        map<int,int>mp;
        for(auto i:nums)mp[i]++;
        int maxm=0;
        for(auto i:mp)
            maxm=max(i.second,maxm);
        int ans=0;
        for(auto i:mp){
            if(i.second==maxm)
                ans+=maxm;
            cout<<ans;
        }
        return ans;
    }
};