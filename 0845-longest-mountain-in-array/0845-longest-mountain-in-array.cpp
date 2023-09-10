class Solution {
public:
    int longestMountain(vector<int>& nums) {
          int n=nums.size();
        if(n<=2)return 0;
          int len=0;
        for(int i=1;i<n-1;i++){
            if(nums[i]>nums[i-1] && nums[i]>nums[i+1]){
                int left=i-1;
                int right=i+1;
                
                while(left>0 && nums[left]>nums[left-1])left--;
                
                while(right<n-1 && nums[right]>nums[right+1])right++;
                
                len=max(len,right-left+1);
            }
        }
        return len;
    }
};