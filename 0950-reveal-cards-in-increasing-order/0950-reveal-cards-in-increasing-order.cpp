class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& d) {
        sort(d.begin(),d.end());
          queue<int>q;
        int n=d.size();
        for(int i=0;i<n;i++)q.push(i);
        
        int i=0;
        vector<int>ans(n);
        while(!q.empty()){
            int x=q.front();
            q.pop();
           ans[x]= d[i];
            if(!q.empty()){
            int y=q.front();
                 q.push(y);
            q.pop();
            // q.push(y);
            }
            i++;
        }
        return ans;
    }
};