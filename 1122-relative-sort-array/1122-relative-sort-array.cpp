class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int,int>mp;
        for(auto i:arr1)mp[i]++;
        vector<int>ans;
        for(int i=0;i<arr2.size();i++){
            if(mp.find(arr2[i])!=mp.end()){
                while(mp[arr2[i]]--)
                    ans.push_back(arr2[i]);
            }
            mp[arr2[i]]=0;
        }
        for(auto i:mp){
            if(i.second!=0){
                while(i.second--)
                    ans.push_back(i.first);
            }
        }
        
        return ans;
    }
};