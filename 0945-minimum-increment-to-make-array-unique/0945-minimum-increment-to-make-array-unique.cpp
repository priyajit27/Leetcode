class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        // 1,1,2,2,3,7
        sort(nums.begin(),nums.end());
        int ans=0;
        for(int i=1;i<nums.size();i++){
             if(nums[i-1]>=nums[i]){
                 ans+=(nums[i-1]-nums[i]+1);
                nums[i]+=(nums[i-1]-nums[i]+1);
             }
        }
        return ans;
    }
};