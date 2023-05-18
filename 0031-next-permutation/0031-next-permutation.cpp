class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // using STL
        // next_permutation(nums.begin(),nums.end());
        
        // optimal
        int index=-1;
        int n=nums.size();
        for(int i=n-2;i>=0;i--){
            if(nums[i+1]>nums[i]){
                index=i;
                break;
            }
        }
         for(int i=n-1;i>=index && index!=-1 ;i--){
            if(nums[index]<nums[i]){
                swap(nums[i],nums[index]);
                break;
            }
        }
        reverse(nums.begin()+index+1,nums.end());
    }
};