class Solution {
public:
    int peakIndexInMountainArray(vector<int>& nums) {
          // int maxm=*max_element(nums.begin(),nums.end());
        // for(int i=0;i<nums.size();i++){
        //     if(nums[i]==maxm)
        //     return i;
        // }
        // return 0;

        // binary search
        int l=0;
        int e=nums.size()-1;
        int mid;
        while(l<=e){
            mid=(l+e)/2;
            if(nums[mid]>nums[mid+1] && nums[mid]>nums[mid-1])
            return mid;
            if(nums[mid]<nums[mid+1])
            l=mid+1;
            else
            e=mid-1;
        }
        return -1;
    }
};