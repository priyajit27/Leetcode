class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left=0;
        int right=0;
        int n=nums.size();
        int count=0,ans=0;
        while(right<n){
            if(nums[right]==0)
                count++;
            while(count>k){
                if(nums[left]==0)
                count--;
                left++;
            }
            // right++;
            ans=max(ans,right-left+1);
            right++;
        }
        return ans;
    }
};