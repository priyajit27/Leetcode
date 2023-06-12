class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
          if(nums.size()==0)
        return {};
        vector<string>ans;
         int start=-1;
            int end=-1;
        for(auto i:nums){
            if(start==-1)
            start=end=i;
            else if(i==end+1)
            end=i;
            else{
               if(start!=end)
               ans.push_back(to_string(start)+"->"+to_string(end));
               else
                ans.push_back(to_string(start));
                start=end=i;
            }
        }
         if(start!=end)
               ans.push_back(to_string(start)+"->"+to_string(end));
               else
                ans.push_back(to_string(start));
        return ans;
    }
};