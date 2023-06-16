class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // set<int>s;
        // for(int i=0;i<nums.size();i++){
        //     s.insert(nums[i]);
        // }
        // int j=0;
        // for(auto i:s)
        //     nums[j++]=i;
        // return s.size();
        
        if(nums.size()==0)
            return 0;
        
        int i=0;
        for(int j=1;j<nums.size();j++){
            if(nums[i]!=nums[j]){
                i++;
                nums[i]=nums[j];
                // i++;
            }
        }
        return i+1;
    }
};