class Solution {
public:
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        int mod=1e9+7;
         int n = nums.size();
        long long ans = 1;
      vector<int>one;
        for(int i=0;i<n;i++){
            if(nums[i]==1)
                one.push_back(i);
        }
         if(one.size()==0)
              return 0;
          if(one.size()==1)
              return 1;
        
        for(int i=1;i<one.size();i++){
            int a=one[i];
            int b=one[i-1];
            // ans=ans%mod;
            ans=(ans*(a-b))%mod;
        }
        return (int)ans%mod;
    }
};