class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
         vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        int count=3;
        for(int i=0;i<nums.size();i+=3){
            if(nums[i+2]-nums[i]>k)
                return {};
        }
        for(int i=0;i<nums.size();i+=3){
            vector<int>a;
            for(int j=0;j<3;j++){
                a.push_back(nums[i+j]);
            }
            ans.push_back(a);
        }
        
        return ans;
    }
};