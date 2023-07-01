class Solution {
public:
     int check(vector<int>& arr, int k){
        int sum=0;
        for(int i=0;i<arr.size();i++){
            sum+=ceil((double)(arr[i])/(double)(k));
        }
        return sum;
    }
         
    int smallestDivisor(vector<int>& nums, int limit) {
         int n=nums.size();
        if(n>limit)
            return -1;
        
         int low=1;
        int high=0;
        for(int i=0;i<nums.size();i++){
            high=max(high,nums[i]);
        }
        
        int ans=0;
        
        while(low<=high){
            int mid=low+(high-low)/2;
             int sum=check(nums,mid);
            
            if(sum<=limit){
                ans=mid;
                high=mid-1;
            }
            else
              low=mid+1;  
        }
        return low;
        
    }
};