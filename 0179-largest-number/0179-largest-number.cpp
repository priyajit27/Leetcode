class Solution {
public:
    bool static comp(int a,int b){
        string ab=to_string(a)+to_string(b);
         string ba=to_string(b)+to_string(a);
        return ab>ba;
    }
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end(),comp);
        for( auto i:nums)
            cout<<i;
        string ans="";
        for(int i=0;i<nums.size();i++){
            ans+=to_string(nums[i]);
        }
          if(ans[0]=='0')
            return "0";
        return ans;
    }
};