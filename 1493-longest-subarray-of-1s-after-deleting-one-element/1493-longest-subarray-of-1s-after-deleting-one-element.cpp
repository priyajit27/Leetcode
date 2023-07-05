class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        //  TC : O(N) || SC : O(1)
        int i=0,j=0;
        int ans=INT_MIN;
        int count0=0;
        while(j<nums.size()){
            if(nums[j]==0)count0++;
            
            while(count0>1){
                 if(nums[i]==0)count0--;
                i++;
            }
           ans=max(ans,j-i+1) ;
            j++;
        }
        
//         We donot have to take that 0 so ans-1
        return ans-1;
    }
};