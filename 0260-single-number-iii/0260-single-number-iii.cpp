class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int>a;
         map<int,int>mp;
        for(auto i:nums)
        mp[i]++;
        for(auto i:mp){
            if(i.second==1)
            a.push_back(i.first);
        }
        return a;
    }
};