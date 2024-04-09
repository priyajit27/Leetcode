class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<int>q;
        int n=tickets.size();
        for(int i=0;i<n;i++)q.push(i);
        
        int t=0;
        while(!q.empty()){
            int x=q.front();
            q.pop();
            tickets[x]--;
            t++;
            
            if(tickets[x]==0 && x==k)return t;
            
            if(tickets[x]>0)
                q.push(x);  
            
        }
        return t;
    }
};