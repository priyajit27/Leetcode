class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long ans=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            auto a=lower_bound(nums.begin(),nums.begin()+i,lower-nums[i]);
            auto b=upper_bound(nums.begin(),nums.begin()+i,upper-nums[i]);
            if(b>=a)
            ans+=b-a;
        }
        return ans;
    }
};