class Solution {
public:
    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {
        map<long long,long long>mp;
         vector<long long>ans;
        priority_queue<pair<long long,long long>>pq;
        // ans.push_back(freq[i]);
        // int maxm=0;
        for(int i=0;i<nums.size();i++){
            if(freq[i]<0){
                   mp[nums[i]]+=freq[i];
                // maxm=0;
                // if(mp[freq[i]]==0)
                //     mp.erase(freq[i]);
                if(pq.top().second==nums[i]){
                     while(pq.top().first!=mp[pq.top().second]){
                         long long first=pq.top().first;
                         long long second=pq.top().second;
                          pq.pop();
                           pq.push({mp[second],second}) ;
                      }
                }
            //        for(auto i:mp){
            //     maxm=max(maxm,i.second);
            // }
                if(pq.size()==0){
                   ans.push_back(0);
                    continue;
                }
                  ans.push_back(pq.top().first);      
            }
            
            else{
                mp[nums[i]]+=freq[i];
            // for(auto i:mp){
            //     maxm=max(maxm,i.second);
            // }
                pq.push({mp[nums[i]],nums[i]});
            
            ans.push_back(pq.top().first); 
            }}
        return ans;
    }
};