class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
          vector<int>odd;
         vector<int>even;
        for(int i=0;i<nums.size();i++){
            if(i%2==0)
                even.push_back(nums[i]);
        }
        sort(even.begin(),even.end());
           for(int i=0;i<nums.size();i++){
            if(i%2==1)
                odd.push_back(nums[i]);
        }
             sort(odd.begin(),odd.end());  
       
         // vector<int>ans;
        int e=0,o=odd.size()-1;
        for(int i=0;i<nums.size();i++){
            if(i%2==0 && e<even.size()){
                nums[i]=even[e++];
            }else if(i%2!=0 && o>=0){
                nums[i]=odd[o--];
            }
        }
        return nums;
    }
};