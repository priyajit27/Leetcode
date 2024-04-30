class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int xr=0;
        for(auto i:nums)
            xr^=i;
        xr^=k;
        int ans=0;
      for(int i=0;i<31;i++){
          if((1<<i)&xr)
              ans++;
      }
        return ans;
    }
};