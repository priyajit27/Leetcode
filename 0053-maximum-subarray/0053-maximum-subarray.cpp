class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxm=INT_MIN;
        int sum=0;
        for(auto i:nums){
            sum+=i;
            maxm=max(maxm,sum);
            if(sum<0)
            sum=0;
        }
        return maxm;
    }
};