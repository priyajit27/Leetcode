class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0;
        int j=0;
        int ans=0;
        int prod=1;
        if(k==0 || k==1)return 0;
        while(j<n){
           prod*=nums[j];
            // if(prod<k){
            //     ans+=j-i+1;
            //     cout<<ans<<" ";
            // }
            while(prod>=k){
                 prod/=nums[i];
                 i++;
              // prod/=nums[i]
            }
            ans+=j-i+1;
            j++;
        }
        return ans;
    }
};