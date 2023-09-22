class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        int sum=accumulate(nums.begin(),nums.end(),0);
        int reqd=sum-x;
        
        if(reqd<0)return -1;
        
        int newsum=0;
        int j=0;
        int ans=-1e9;
        for(int i=0;i<n;i++){
            newsum+=nums[i];
            
            while(newsum>reqd){
                newsum-=nums[j];
                j++;
            }
            if(newsum==reqd)
                ans=max(ans,i-j+1);
        }
        
        if(ans==-1e9)
            return -1;
        return n-ans;
    }
};