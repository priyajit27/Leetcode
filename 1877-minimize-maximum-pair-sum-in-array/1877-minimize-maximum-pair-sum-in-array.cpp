class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int maxsum=INT_MIN;
        int i=0;
        int j=nums.size()-1;
        while(i<=j){
            int sum=nums[i]+nums[j];
            if(sum>maxsum)
                maxsum=sum;
            i++;j--;
        }
        return maxsum;
    }
};