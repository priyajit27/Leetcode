class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        int prod=1;
        
        int count=0;
         for(int i=0;i<n;i++){
             if(nums[i]==0)
                 count++;
         }
          vector<int>ans;
      
        for(int i=0;i<n;i++){
            if(nums[i]==0)
                continue;
            else
                prod*=nums[i];
        }
          // vector<int>ans;
          for(int i=0;i<n;i++){
            if(count>=2){
                ans.push_back(0);
            }
           else if(nums[i]==0)
                ans.push_back(prod);
              
              else{
                  if(count==1)
                   ans.push_back(0);
                      else
                          ans.push_back(prod/nums[i]);  
                      
              }
                 // ans.push_back(prod/nums[i]);   
        }
        return ans;
    }
};