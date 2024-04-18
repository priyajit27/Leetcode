class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int sum=nums[0]+nums[1]+nums[2];
        int sum1=0;
        
        for(int i=0;i<n;i++){
            int front=i+1;
            int back=n-1;
            
            while(front<back){
                
                sum1=nums[i]+nums[front]+nums[back];
                
                if(abs(sum1-target)<abs(sum-target)){
                  sum=sum1;  
                }
                
                else if(sum1>target)back--;
                
                else if(sum1<target)front++;
                
                else return sum1;
            }
             
        }
        
        return sum;
    }
};