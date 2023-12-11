class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        map<int,int>mp;
        for(auto i:arr){
            mp[i]++;
        }
        int n=arr.size();
        int ans=-1;
        for(auto i:mp){
            if(i.second>n/4){
                 ans=i.first;
            }
        }
        return ans;
    }
};