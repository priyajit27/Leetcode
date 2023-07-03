class Solution {
public:
    bool canJump(vector<int>& nums) {
          if(nums.size()==0 || nums.size()==1)
        return true;
        int d=0;
      for(int i=0;i<nums.size()-1;i++){
               d=max(d,nums[i]+i);
               if(d==i)return false;
      }
      return true; 
    }
};