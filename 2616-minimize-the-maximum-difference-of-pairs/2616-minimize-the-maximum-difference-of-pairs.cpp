class Solution {
public:
    bool possible(vector<int>& nums,int mid,int p){
        int i=0;
        while(i<nums.size()-1){
            if(abs(nums[i]-nums[i+1])<=mid){
                p--;
                i+=2;
            }
            else
                i++;
        }
        if(p<=0)
            return true;
        return false;
    }
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(),nums.end());
        int low=0;
        int high=nums[nums.size()-1];
        int ans=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(possible(nums,mid,p)){
                ans=mid;
                high=mid-1;
            }
            else
                low=mid+1;
        }
        return ans;
    }
};