class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>,vector<string>>mp;
        int n=strs.size();
        
        for(int i=0;i<n;i++){
            string temp=strs[i];
            vector<int>freq(26,0);
            for(auto &it:temp){
                freq[it-'a']++;
            }
            mp[freq].push_back(temp);
        }
        vector<vector<string>>ans;
        for(auto &it:mp)
            ans.push_back(it.second);
        return ans;
    }
};