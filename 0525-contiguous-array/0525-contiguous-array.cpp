class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0)
            nums[i]=-1;
            else continue;
        }
        int k=0;
       map<int,int>mp;
        int sum=0;
        int count=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum==0)
                count=max(count,i+1);
            
            if(mp.find(sum)!=mp.end())
              count=max(count,i-mp[sum-k]);
            
           else  mp[sum]=i;
        }
        return count;
    }
};