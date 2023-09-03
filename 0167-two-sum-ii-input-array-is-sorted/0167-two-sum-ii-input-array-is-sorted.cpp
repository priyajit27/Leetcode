class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
           vector<int>a;
        unordered_map<int,int>mp;
        // for(int i=0;i<nums.size();i++){
        //     mp[nums[i]]=i;
        // }
         for(int i=0;i<nums.size();i++){
         if(mp.find(target-nums[i]) !=mp.end()){
             a.push_back(mp[target-nums[i]]+1);
             a.push_back(i+1);
             return a;
         }
          mp[nums[i]]=i;
         }
         return {-1,1};
    }
};