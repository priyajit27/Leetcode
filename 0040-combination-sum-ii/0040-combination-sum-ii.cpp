class Solution {
public:
     void rec(int index,int target,vector<vector<int>>& ans,int n,vector<int>& nums,vector<int>& path){
 
        if(target==0){
        ans.push_back(path);
        return;
    }
//     // pick
//          if(arr[index]<=target){
//               path.push_back(arr[index]);
//               rec(index+1,target-arr[index],ans,n,arr,path);
//              path.pop_back();
//          }
    
//     // not pick
//      rec(index+1,target,ans,n,arr,path);
         for(int i=index;i<nums.size();i++){
             if(i!=index && nums[i]==nums[i-1])continue;
             if(nums[i]>target)break;
             path.push_back(nums[i]);
               rec(i+1,target-nums[i],ans,n,nums,path);
             path.pop_back();
         }
         
}
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
          int N=nums.size();
        sort(nums.begin(),nums.end());
          // set<vector<int>>ans;
        vector<int>path;
         vector<vector<int>>ans;
         rec(0,target,ans,N,nums,path);
         // vector<vector<int>>ans1;
        
         return ans;
    }
};