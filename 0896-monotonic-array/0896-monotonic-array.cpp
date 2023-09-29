class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int ok=1;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]-nums[i+1]>=0){
                ok++;
                // continue;
            }
        }
        cout<<ok;
        if(ok==nums.size())
            return true;
        ok=1;
          for(int i=nums.size()-2;i>=0;i--){
            if(nums[i+1]-nums[i]>=0)
              ok++;
        }
        if(ok==nums.size())
            return true;
        return false;
    }
};