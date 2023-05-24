class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
           vector<pair<double,int>>v;
        for(int i=0;i< quality.size();i++){
            v.push_back({wage[i]/double(quality[i]), quality[i]});
        }
//         descending order
        sort(v.begin(),v.end());
        
         double ans=INT_MAX;
         double sum=0;
        priority_queue<int>pq;
        for(int i=0;i<k-1;i++){
            sum+=v[i].second;
            pq.push(v[i].second);
        }
         for(int i=k-1;i< quality.size();i++){
            sum+=v[i].second;
            pq.push(v[i].second);
             ans=min(ans,sum*v[i].first);
             sum-=pq.top();
             pq.pop();
        }
        
        return ans;
    }
};