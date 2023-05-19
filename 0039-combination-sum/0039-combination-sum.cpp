class Solution {
public:
     void rec(int index,int target,vector<vector<int>>& ans,int n,vector<int>& arr,vector<int>& path){
    if(index==n){
        if(target==0)
        ans.push_back(path);
        return;
    }
    // pick
         if(arr[index]<=target){
              path.push_back(arr[index]);
              rec(index,target-arr[index],ans,n,arr,path);
             path.pop_back();
         }
    
    // not pick
     rec(index+1,target,ans,n,arr,path);
}
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
         int N=nums.size();
          vector<vector<int>>ans;
        vector<int>path;
         rec(0,target,ans,N,nums,path);
         return ans;
    }
};