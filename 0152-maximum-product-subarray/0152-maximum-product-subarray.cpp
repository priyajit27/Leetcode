class Solution {
public:
    int maxProduct(vector<int>& nums) {
//        approach 1
        // int n=nums.size();
        // int ans=INT_MIN;
        // for(int i=0;i<n-1;i++){
        //     for(int j=i+1;j<n;j++){
        //         int prod=1;
        //         for(int k=i;k<=j;k++)
        //             prod*=nums[k];
        //         ans=max(prod,ans);   
        //     }
        // }
        // return ans;
        
//     approach 2     
        int rightmax=INT_MIN;int leftmax=INT_MIN;
         int n=nums.size();
        int prod=1;
        for(int i=0;i<n;i++){
            prod*=nums[i];
            leftmax=max(leftmax,prod);
            if(prod==0)
                prod=1;
        }
         prod=1;
          for(int i=n-1;i>=0;i--){
              prod*=nums[i];
            rightmax=max(rightmax,prod);
            if(prod==0)
                prod=1;
        }
        return max(leftmax,rightmax);
    }
};