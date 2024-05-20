class Solution {
public:
    int rec(int index,int ans,int n,vector<int>& arr){
    if(index==n){
        // ans.push_back(path);
        return ans;
    }
    
    // pick
        int x=arr[index];
        // path.push_back(arr[index]);
    int take=rec(index+1,ans^x,n,arr);
    
    // not pick
        // path.pop_back();
    int not_take=rec(index+1,ans,n,arr);
        return take + not_take;
}
    int subsetXORSum(vector<int>& nums) {
         int N=nums.size();
          int ans=0;
        // vector<int>path;
         return rec(0,ans,N,nums);
    }
};