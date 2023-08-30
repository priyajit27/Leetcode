class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        int n=nums.size();
        long long ans=0;
        long long maxmin=nums[n-1];
        for(int i=n-2;i>=0;i--){
            int part=ceil(nums[i]/double(maxmin));
            ans+=part-1;
            maxmin=nums[i]/part;
        }
        return ans;
    }
};