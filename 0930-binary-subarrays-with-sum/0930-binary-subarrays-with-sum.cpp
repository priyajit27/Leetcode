class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
//         Brute force
        // int n=nums.size();
        // int ans=0;
        // for(int i=0;i<n;i++){
        //     int sum=0;
        //     for(int j=i;j<n;j++){
        //         sum+=nums[j];
        //         if(sum==goal)
        //             ans++;
        //     }
        // }
        // return ans;
        
        // hashing O(n) O(n)
          int n=nums.size();
        map<int,int>mp;
        mp[0]=1;
        int count=0;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(mp.find(sum-goal)!=mp.end())
                count+=mp[sum-goal];
                mp[sum]++;
        }
        return count;
    }
};