class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int right=0;
        int left=0;
        int sum=0;
        int len=INT_MAX;   
        while(right<n){
            sum+=nums[right];
            while(sum>=target){
                 len=min(len,right-left+1);
                sum-=nums[left];
                 left++;
            }
            right++;
            // if(right<n)
            //     sum+=nums[right];
        }
        if(len==INT_MAX)
            return 0;
        return len;
    }
};