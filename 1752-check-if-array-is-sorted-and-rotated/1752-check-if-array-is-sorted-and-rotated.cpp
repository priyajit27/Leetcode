class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size();
      for(int i=1;i<nums.size();i++){
          if(nums[i]>=nums[i-1])
              continue;
          else if(nums[i]<=nums[i-1]){
              if(nums[0]<nums[i])
                  return false;
              for(int j=i+1;j<n;j++){
                  if(nums[j]>=nums[j-1] && nums[0]>=nums[j])
                      continue;
                      else
                          return false;
              }
          }
      }
        return true;
    }
};