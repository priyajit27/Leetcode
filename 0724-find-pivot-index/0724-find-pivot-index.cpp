class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int left=0;
        int right=accumulate(nums.begin(),nums.end(),0);
        for(int i=0;i<nums.size();i++){
            left+=nums[i];
            if(left==right)
                return i;
            right-=nums[i];
        }
        return -1;
    }
};