class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        int one=0;
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                one++;
            }
            else
                one=0;
            ans=max(ans,one);
        }
        return ans;
    }
};