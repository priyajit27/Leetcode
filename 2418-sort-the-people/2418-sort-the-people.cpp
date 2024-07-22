class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        map<int,string>mp;
        for(int i=0;i<names.size();i++){
            mp[heights[i]]=names[i];
        }
         vector<string>ans;
        // sort(mp.begin(),mp.end());
        for(auto i:mp)
            ans.push_back(i.second);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};