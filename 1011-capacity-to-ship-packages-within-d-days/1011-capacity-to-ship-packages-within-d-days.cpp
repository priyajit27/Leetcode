class Solution {
public:
    int check(vector<int>& nums, int capacity){
        int day=1;
        int load=0;
        for(int i=0;i<nums.size();i++){
            if(load+nums[i]>capacity){
                day+=1;
                load=nums[i];
            }
              else
                  load+=nums[i];
            
        }
        
        return day;
    }
    int shipWithinDays(vector<int>& nums, int days) {
         int n=nums.size();
        
         int low=1;
        int high=accumulate(nums.begin(),nums.end(),0);
        for(int i=0;i<nums.size();i++){
            low=max(low,nums[i]);
        }
        int ans=low;
        while(low<=high){
            int mid=low+(high-low)/2;
             int dayreqd=check(nums,mid);
            
            if(dayreqd<=days){
                ans=mid;
                high=mid-1;
            }
            else
              low=mid+1;  
        }
        return ans;
    }
};