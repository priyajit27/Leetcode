class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
          unordered_map<int,int> freq;

        for(auto i: nums)
            freq[i]++;

        map<int,vector<int>> freqGrp;

        for(auto i: freq)
          freqGrp[i.second].push_back(i.first);

        vector<int> ans;
        
        for(auto it: freqGrp){
            if(it.second.size() > 1)
                
         sort(it.second.rbegin(), it.second.rend());
            
            for(auto num: it.second){
            for(int i=0;i<it.first;i++)
                    ans.push_back(num);
                
            }}

        return ans;
    }
};