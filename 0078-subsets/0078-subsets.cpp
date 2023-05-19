class Solution {
public:
    void rec(int index,vector<vector<int>>& ans,int n,vector<int>& arr,vector<int>& path){
    if(index==n){
        ans.push_back(path);
        return;
    }
    
    // pick
        path.push_back(arr[index]);
    rec(index+1,ans,n,arr,path);
    
    // not pick
        path.pop_back();
     rec(index+1,ans,n,arr,path);
}
    vector<vector<int>> subsets(vector<int>& nums) {
        int N=nums.size();
          vector<vector<int>>ans;
        vector<int>path;
         rec(0,ans,N,nums,path);
         return ans;
    }
};