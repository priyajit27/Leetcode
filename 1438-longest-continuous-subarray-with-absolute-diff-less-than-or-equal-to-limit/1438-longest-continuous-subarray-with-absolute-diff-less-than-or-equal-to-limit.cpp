class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int i=0;
        int n=nums.size();
        int ans=1;
       multiset<int>s;
        for(int j=0;j<n;j++){
            s.insert(nums[j]);
            // int begin=*s.begin();
            // int end=*s.rbegin();
               while(abs(*s.begin()-*s.rbegin())>limit){
                   s.erase(s.find(nums[i]));
                   i++;
               }
            // int x=s.size();
            ans=max(ans,j-i+1);
        }
        return ans;
    }
};