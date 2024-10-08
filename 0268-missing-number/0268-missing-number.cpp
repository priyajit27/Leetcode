class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
       int xr1=0;
        // int xr2=0;
        for(int i=0;i<n;i++){
            xr1^=nums[i];
            xr1^=i;
        }
         xr1^=n;   
        return xr1;
    }
};