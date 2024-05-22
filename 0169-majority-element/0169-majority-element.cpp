class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // int count=0;
        // int maxm=0;
        // sort(nums.begin(),nums.end());
        // for(int i=1;i<=nums.size();i++){
        //     if(a[i]==a[i-1])
        //         count++;
        //     else 
        //         count=0;
        //     maxm=max(maxm,count);
        // }
        // return maxm
        
        int count=0;
        int element=0;
        for(int i=0;i<nums.size();i++){
            if(count==0){
                element=nums[i];
                count++;
            }
            else if(element==nums[i]){
                count++;
            }
            else
                count--;
        }
        return element;
    }
};