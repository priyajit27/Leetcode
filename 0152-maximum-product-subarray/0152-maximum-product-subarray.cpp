class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int maxm=INT_MIN;
        int suff=1;
        int pre=1;
        for(int i=0;i<n;i++){
            if(suff==0)
                suff=1;
            if(pre==0)
                pre=1;
            pre*=nums[i];
            suff*=nums[n-1-i];
            maxm=max(maxm,max(suff,pre));
        }
        return maxm;
    }
};