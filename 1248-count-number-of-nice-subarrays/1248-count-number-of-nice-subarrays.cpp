class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        // N^2 solution
        // int n=nums.size();
        // for(int i=0;i<n;i++){
        //     if(nums[i]%2)
        //         nums[i]=1;
        //     else
        //         nums[i]=0;
        // }
        // int ans=0;
        // for(int i=0;i<n;i++){
        //     int sum=0;
        //     for(int j=i;j<n;j++){
        //         sum+=nums[j];
        //         if(sum==k)
        //             ans++;
        //     }
        // }
        // return ans;
        
//     O(N)  O(N)
         int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]%2)
                nums[i]=1;
            else
                nums[i]=0;
        }
        map<int,int>mp;
        int count=0;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(sum==k)
                count++;
            if(mp.find(sum-k)!=mp.end())
               count+= mp[sum-k];
            
            mp[sum]++;
        }
        return count;
    }
};