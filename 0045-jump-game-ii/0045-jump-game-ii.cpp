class Solution {
public:
    int jump(vector<int>& nums) {
         int jumps=0;
       int far=0;
       int current=0;
       for(int i=0;i<nums.size()-1;i++){
           far=max(far,nums[i]+i);
          if(i==current){
              current=far;
              jumps++;
          }
       }
       return jumps;
    }
};