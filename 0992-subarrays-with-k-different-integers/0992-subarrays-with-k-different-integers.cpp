class Solution {
public:
       int check(vector<int>& s,int k){
            int n=s.size();
         vector<int>v(n+1,0);
         if(s.size()==0)
        return 0;
        int ans=0;
        int left=0;
        int count=0;
        for(int i=0;i<n;i++){
            if(v[s[i]]==0)
            count++;
            v[s[i]]++;
            
        while(count>k){
            v[s[left]]--;
            if(v[s[left]]==0)
            count--;
            left++;
        }
            ans+=i-left+1;
        }
        
        return ans;
  }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
         return check(nums,k)-check(nums,k-1);
    }
};