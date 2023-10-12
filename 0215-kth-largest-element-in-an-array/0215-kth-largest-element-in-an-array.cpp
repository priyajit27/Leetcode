class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int ans=-1;
        for(int i=0;i<nums.size()-k+1;i++)
            ans=nums[i];
        return ans;
        
    }
};