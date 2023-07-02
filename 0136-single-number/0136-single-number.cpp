class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // unordered_map<int,int>mp;
        // for(auto i:nums){
        //     mp[i]++;
        // }
        // for(auto i:mp)
        //     if(i.second==1)
        //      return i.first;
        // return -1;
        
//         Using XOR
        int xr=0;
        for(int i=0;i<nums.size();i++){
            xr^=nums[i];
        }
        return xr;
    }
};