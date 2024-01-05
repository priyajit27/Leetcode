class Solution {
public:
    int minOperations(vector<int>& nums) {
        map<int,int>mp;
        for(auto i:nums)
            mp[i]++;
        int ans=0;
        for(auto i:mp){
           int num=i.second;
            if(num==1)return -1;
            // if(num%3==0)
                ans+=num/3;
            if(num%3)
                ans++;
        }
        return ans;
    }
};