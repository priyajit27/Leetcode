class Solution {
public:
    int findDuplicate(vector<int>& nums) {
//         Approach 3 using linked list
       int slow=nums[0];
        int fast=nums[0];
        
        do{
          slow=nums[slow]  ;
            fast=nums[nums[fast]];
        }
        while(fast!=slow);
           
            fast=nums[0];
        while(slow!=fast){
            slow=nums[slow];
            fast=nums[fast];
        }
        // return slow;
        return fast;
    }
};