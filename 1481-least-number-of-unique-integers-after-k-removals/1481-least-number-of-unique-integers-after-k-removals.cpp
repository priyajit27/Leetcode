class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        map<int,int>mp;
        for(auto i:arr)
            mp[i]++;
        vector<pair<int,int>>v(mp.size());
        int j=0;
        for(auto i:mp){
          v[j].first=i.second;
            v[j].second=i.first;
               j++;
        }
        int ans=v.size();
        sort(v.begin(),v.end());
         j=0;
        while(k>0){
            while(v[j].first>0 && k>0){
                v[j].first--;
                k--;
            }
            if(v[j].first==0){
                j++;
                ans--;
            }
        }
        return ans;
    }
};