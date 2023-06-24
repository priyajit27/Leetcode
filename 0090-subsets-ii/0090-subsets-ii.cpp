class Solution {
public:
      void rec(int index,vector<vector<int>>& ans,int n,vector<int>& nums,vector<int>& path){
//     if(index==n){
//         ans.insert(path);
//         return;
//     }
    
//     // pick
//         path.push_back(arr[index]);
//     rec(index+1,ans,n,arr,path);
    
//     // not pick
//         path.pop_back();
//      rec(index+1,ans,n,arr,path);
        ans.push_back(path)  ;
           for(int i=index;i<nums.size();i++){
             if(i!=index && nums[i]==nums[i-1])continue;
             path.push_back(nums[i]);
               rec(i+1,ans,n,nums,path);
             path.pop_back();
         }
          
}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
          sort(nums.begin(),nums.end());
          int N=nums.size();
          vector<vector<int>>ans;
        vector<int>path;
         rec(0,ans,N,nums,path);
        //   vector<vector<int>>ans1;
        // for(auto i:ans){
        //     ans1.push_back(i);
        // }
         return ans;
    }
};