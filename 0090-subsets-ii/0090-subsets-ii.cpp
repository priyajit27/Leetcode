class Solution {
public:
      void rec(int index,set<vector<int>>& ans,int n,vector<int>& arr,vector<int>& path){
    if(index==n){
        ans.insert(path);
        return;
    }
    
    // pick
        path.push_back(arr[index]);
    rec(index+1,ans,n,arr,path);
    
    // not pick
        path.pop_back();
     rec(index+1,ans,n,arr,path);
}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
          sort(nums.begin(),nums.end());
          int N=nums.size();
          set<vector<int>>ans;
        vector<int>path;
         rec(0,ans,N,nums,path);
          vector<vector<int>>ans1;
        for(auto i:ans){
            ans1.push_back(i);
        }
         return ans1;
    }
};