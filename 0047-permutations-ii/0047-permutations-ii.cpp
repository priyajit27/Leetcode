class Solution {
public:
      void repermute( vector<int>& ds,vector<int>& nums,set<vector<int>>& ans,int fre[]){
      if(ds.size()==nums.size()){
          ans.insert(ds);
        //   return;
      }
      for(int i=0;i<nums.size();i++){
           if(!fre[i]){
               ds.push_back(nums[i]);
               fre[i]=1;
               repermute(ds,nums,ans,fre);
                fre[i]=0;
                ds.pop_back();
           }
      }
  }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
          set<vector<int>>ans;
        vector<int>ds;
        // int fre[nums.size()]={0};
        int fre[nums.size()];
        for(int i=0;i<nums.size();i++){
            fre[i]=0;
        }
        repermute(ds,nums,ans,fre);
          vector<vector<int>>ans1;
        for(auto i:ans){
            ans1.push_back(i);
        }
        return ans1;
    }
};