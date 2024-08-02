class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        int window=0;
        for(int i=0;i<n;i++){
            if(nums[i]==1)
              window++  ;
        }
        int count0=0;
        for(int i=0;i<window;i++){
            if(nums[i]==0)
                count0++;
        }
        // int count0=0;
        int ans=count0;
        
         for(int i=window;i<n+window;i++){
            if(nums[i%n]==0)
                count0++;
              if(nums[i-window]==0)
                count0--;
             ans=min(ans,count0);
        }
        
        
        return ans;
    }
};