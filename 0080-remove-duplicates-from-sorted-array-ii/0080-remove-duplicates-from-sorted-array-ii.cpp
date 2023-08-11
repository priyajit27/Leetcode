class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j=0;
        // sort(nums.begin(),nums.end());
        int p=0;
        if(nums.size()==1)return 1;
        for(int i=0;i<nums.size();i++){
            if(i<nums.size()-2 && nums[i]==nums[i+2])
                continue;
            else
                nums[p++]=nums[i];
        }
        return p;
    }
};