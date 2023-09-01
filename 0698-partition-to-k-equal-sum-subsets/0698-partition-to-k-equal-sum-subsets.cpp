class Solution {
public:
    bool rec(int i,int currsum,int target,vector<int>& nums,vector<int>& visited,int k){
        if(k==1)return true;
        if(currsum==target)
            return rec(0,0,target,nums,visited,k-1);
        
        for(int j=i;j<nums.size();j++){
            if(   visited[j]==1 || currsum+nums[j]>target)continue;
                   visited[j] =1;
              if(rec(j+1,currsum+nums[j],target,nums,visited,k))
                  return true;    
            visited[j]=-1;
        }
        return false;
        
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        
        vector<int>visited(nums.size(),-1);
        if(sum%k==1 || k>nums.size())
            return false;
        
        sort(nums.begin(),nums.end(),greater<int>());
        if(nums[0]>sum/k)return false;
        
        return rec(0,0,sum/k,nums,visited,k);
        
    }
};