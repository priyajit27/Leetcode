class Solution {
public:
    int findMaxK(vector<int>& nums) {
        set<int>s;
        for(auto i:nums)s.insert(i);
        for(auto i:s){
            if(i<0){
                if(s.find(-i)!=s.end())
                    return -i;
            }
        }
        return -1;
    }
};