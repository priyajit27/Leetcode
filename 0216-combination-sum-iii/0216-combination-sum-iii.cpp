class Solution {
public:
     vector<vector<int>>ans;
    void rec(int ind,int target,int k, vector<int>& nums, vector<int>& temp){
        
        
        if(target==0 && temp.size()==k){
            ans.push_back(temp);
            return;
        }
        
        
        for(int i=ind;i<nums.size();i++){
            if(nums[i]<=target){
                temp.push_back(nums[i]);
                rec(i+1,target-nums[i],k,nums,temp);
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>nums;
        for(int i=1; i<=9; i++) nums.push_back(i);
           vector<int>temp;
        rec(0,n,k,nums,temp);
        return ans;
    }
};